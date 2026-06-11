#include<stdio.h>

int main(){
	char a[4];
	scanf("%s",a);
	if (a[1]=='B')
	{
		a[0]='A';
		a[1]='R';
		a[2]='C';
		printf("%s",a);
	}
	else if (a[1]=='R')
	{
		a[0]='A';
		a[1]='B';
		a[2]='C';
		printf("%s",a);
	}
	
	return 0;
}