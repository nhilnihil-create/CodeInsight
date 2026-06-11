#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

	double a,b;
	cin>>a>>b;
	int d,r;
	double f;
	d=a/b;
	r=a-d*b;
	f=a/b;
	//cout<<d<<" "<<r<<" "<<f<<endl;
	printf("%d %d %7.5f",d,r,f);


	return 0;
}