#include<stdio.h>
int main(void)
{
	int a,b,s;
	
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			s=a*b;
			printf("%dx%d=%d\n",a,b,s);
		}	
	}
	return 0;
}