
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<cmath>
#include<iomanip>
using namespace std;

int main(void){
	double a,c,d,e,f,dod,ret[1001],w;
	while(1){
	cin>>f;
	if(f==0){
		break;
	}
	for(int b=0;f>b;b++){
		cin>>a;
		ret[b]=a;
		c+=a;
	}
	d=c/f;
	//printf("%.8lf\n",d);
	c=0;
	for(int b=0;f>b;b++){
		e=ret[b]-d;
		dod+=e*e;
		//printf("e=%.8lf\n dod=%.8lf\n",e,dod);
		e=0;
	}
	dod=dod/f;
	printf("%.8lf\n",sqrt(dod));
	dod=0;
	}
	return 0;
}

