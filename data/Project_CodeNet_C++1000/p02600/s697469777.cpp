#include<stdio.h>
int main(){
	int n,x;
	scanf("%d",&n);
	if(n<=599&&n>=400)
	x=8;
		if(n<=799&&n>=600)
	x=7;
		if(n<=999&&n>=800)
	x=6;
		if(n<=1199&&n>=1000)
	x=5;
		if(n<=1399&&n>=1200)
	x=4;
		if(n<=1599&&n>=1400)
	x=3;
		if(n<=1799&&n>=1600)
	x=2;
			if(n<=1999&&n>=1800)
	x=1;
	printf("%d",x);
} 