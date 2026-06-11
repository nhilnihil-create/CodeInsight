#include<stdio.h>

int main(){

int a1, a2;
scanf("%d %d", &a1, &a2);
if ((a1==1&&a2==2)||(a1==2&&a2==1))printf("%d\n", 3);
else if ((a1==1&&a2==3)||(a1==3&&a2==1))printf("%d\n", 2);
else if ((a1==2&&a2==3)||(a1==3&&a2==2))printf("%d\n", 1);

	return 0;
}