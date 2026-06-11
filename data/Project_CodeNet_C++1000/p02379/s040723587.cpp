
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cmath>
#include    <iomanip>
using namespace std;

int main(void){
	double a,b,c,d,e,f,dod;
	cin>>a>>b>>c>>d;
	e=a-c;
	f=b-d;
	dod=pow(e,2)+pow(f,2);
	dod=sqrt(dod);
	cout<<setprecision(12)<<dod<<endl;
	return 0;
}

