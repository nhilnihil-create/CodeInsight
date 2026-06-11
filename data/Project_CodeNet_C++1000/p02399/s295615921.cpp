#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int a,b;
	int d,r;
	
	cin>>a>>b;
	
	d=a/b;
	r=a%b;
	

	printf("%d %d %.9f",d,r,(double)a/b);
	return 0;
}