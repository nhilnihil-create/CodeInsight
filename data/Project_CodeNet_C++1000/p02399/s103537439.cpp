#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,d,r;
	double f;
	cin>>a>>b;
	d=a/b;
	r=a%b;
	f=(double)a/(double)b;
	cout<<d<<' '<<r<<' ';
	printf("%f",f);
	cout<<endl;
	return 0;
}