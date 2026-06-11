#include<stdio.h>
int main ()
{
	char x[10];
	scanf("%s", &x);
	if(x[2]==x[3] && x[4]==x[5]){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}