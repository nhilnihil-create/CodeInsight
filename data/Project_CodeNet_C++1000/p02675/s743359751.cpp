#include <stdio.h> 
 int main(void) {
 int n;
 scanf("%d", &n);

 switch (n % 10) {
 case 2:
 case 4:
 case 5:
 case 7:
 case 9:
 puts("hon");
 break;
 case 0:
 case 1:
 case 6:
 case 8:
 puts("pon");
 break;
 case 3:

puts("bon");
break; }
return 0;
}
 