#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(){
	double d1=0,d2=0,d3=0,di=0;
	int n,m,i,j;
	cin >> n;
	int x[n]={},y[n]={};
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	for(i=0;i<n;i++){
		cin >> y[i];
	}
	for(i=0;i<n;i++){
		j=x[i]-y[i];
		if(j<0){
			j=j*(-1);
		}
		d1 += j;
		d2 += pow(j,2);
		d3 += pow(j,3);
		if(di<j){
			di=j;
		}
	}
	d2=pow(d2,1./2);
	d3=pow(d3,1./3);
	printf("%.8f\n%.8f\n%.8f\n%.8f\n",d1,d2,d3,di);
	return 0;
}