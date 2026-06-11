
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cmath>
#include<iomanip>
using namespace std;

int main(void){
	double a,c,d,e,f,dod,ret[1001],it[1000],w;
	cin>>f;
	d=0.333333333333;
	for(int b=0;f>b;b++){
		cin>>a;
		ret[b]=a;
	}
	for(int b=0;f>b;b++){
		cin>>a;
		it[b]=a;
	}
	for(int b=0;f>b;b++){
		c=ret[b]-it[b];
		if(c<0){
			c=c*-1;
		}
		dod+=c;
	}
	printf("%.8lf\n",dod);
	dod=0;
	for(int b=0;f>b;b++){
		c=ret[b]-it[b];
		dod+=c*c;
	}
	printf("%.8lf\n",sqrt(dod));
	dod=0;
	for(int b=0;f>b;b++){
		c=ret[b]-it[b];
		if(c<0){
			c=c*-1;
		}
		dod+=c*c*c;
	}
	printf("%.8lf\n",pow(dod,d));
	dod=0;
	for(int b=0;f>b;b++){
		c=ret[b]-it[b];
		if(c<0){
			c=c*-1;
		}
		if(dod<c){
			dod=c;
		}
	}
printf("%.8lf\n",dod);
	return 0;
}
