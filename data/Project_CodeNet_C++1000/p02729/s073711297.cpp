#include<stdio.h>
int main (){
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	c = a * (a-1)/2;
	d = b * (b-1)/2;
	
	printf("%d\n",c+d);
	

	return 0;
}