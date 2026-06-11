#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int a,b;
	double f,a1,b1;
	scanf("%d%d",&a,&b);
	a1=a;
	b1=b;
	f=a1/b1;
	printf("%d %d %.5lf\n",a/b,a%b,a1/b1);
	return 0;
}