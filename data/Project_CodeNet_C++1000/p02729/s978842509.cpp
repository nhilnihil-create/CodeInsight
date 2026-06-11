#include<stdio.h>

int main(){
	int a,b,n;
	n=0;
	scanf("%d %d", &a,&b);
	if(a>1) n=n+(a*(a-1)/2);
	if(b>1) n=n+(b*(b-1)/2);
	printf("%d", n);
	return 0;
}