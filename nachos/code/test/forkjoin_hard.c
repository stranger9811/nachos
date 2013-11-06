#include "syscall.h"

int
main()
{
    int x, y=6;

    PrintString("Parent PID: ");
    PrintInt(GetPID());
	int *array = (int*)ShmAllocate(2*sizeof(int));
	array[0] =0;
	PrintInt(GetPA((unsigned)array));
	PrintChar('\n');
    x = Fork();
    if (x == 0) {
       PrintString("Child PID: ");
       PrintInt(GetPID());
       array[0] = 1;
	PrintChar('\n');
       PrintString("Child's parent PID: ");
       PrintInt(GetPPID());
       PrintChar('\n');
       PrintString("Child calling sleep at time: ");
       PrintInt(GetTime());
       PrintChar('\n');
       Sleep(100);
       PrintString("Child returned from sleep at time: ");
       PrintInt(GetTime());
       PrintChar('\n');
       y++;
       PrintString("Child y=");
       PrintInt(y);
       PrintChar('\n');
       x = Fork();
       //Exec("../test/printtest");
       if (x == 0) {
          PrintString("Child PID: ");
          PrintInt(GetPID());
          PrintChar('\n');
          y++;
          PrintString("Child2 y=");
          PrintInt(y);
          PrintChar('\n');
          Exit(20);
       }
       else {
          PrintString("Parent after fork waiting for child: ");
          PrintInt(x);
          PrintChar('\n');
          PrintString("Parent2 join value: ");
          PrintInt(Join(x));
          PrintChar('\n');
          PrintString("Parent2 y=");
          PrintInt(y);
          PrintChar('\n');
          Exit(10);
       }
    }
    else {
       PrintString("Parent after fork waiting for child: ");
       PrintInt(x);
	PrintChar('\n');
       PrintString("Parent2 join value: ");
       PrintInt(Join(x));
       PrintChar('\n');
        PrintString("shared value = ");
          PrintInt(array[0]);
          PrintString("\n\n\n\n\n\n\n\n\n\n\n\n");
       PrintString("Parent y=");
       PrintInt(y);
       PrintChar('\n');
       Exit(1);
    }
    return 0;
}
