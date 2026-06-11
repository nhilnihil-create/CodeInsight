#include<stdio.h>
int main(){
	int x,y,d,r;
	double f;
	scanf("%d %d",&x,&y);
	d=x/y;
	r=x%y;
	f=(double)x/y;
	printf("%d %d %lf\n",d,r,f);
return 0;
}