#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){
	int a,b;
	
	cin>>a>>b;
	
	cout<<a/b<<' '<<a%b<<' ';
	printf("%.8lf\n",(double)a/b);
	return 0;
}