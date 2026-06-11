#include <stdio.h>
int main() {
 int h,a;
 scanf("%d %d",&h,&a);
 int x = h/a;
 int z = h%a;
 if (z==0)
 		printf("%d",x);
	else 
		printf("%d", ++x);
return 0;
}
