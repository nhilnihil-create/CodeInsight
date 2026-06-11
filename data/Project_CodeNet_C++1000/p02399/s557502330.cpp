#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,d,r;
	double x,y,f;
	cin>>a>>b;
	d=a/b;
	r=a%b;
	x=a;
	y=b;
	f=x/y;
	cout<<d<<" "<<r<<" ";
	printf("%f5",f);
	cout<<endl;
	return 0;
}