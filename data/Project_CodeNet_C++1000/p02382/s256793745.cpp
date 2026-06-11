#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	double x[101],y[101],P1=0.0,P2=0.0,P3=0.0,P4=0.0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>y[i];
	}
	for(int i=1;i<=n;i++){
		P1+=abs(x[i]-y[i]);
		P2+=pow(abs(x[i]-y[i]),2);
		P3+=pow(abs(x[i]-y[i]),3);
		if(P4<abs(x[i]-y[i])){
			P4=abs(x[i]-y[i]);
		}
	}
	printf("%.6lf\n%.6lf\n%.6lf\n%.6lf\n",P1,pow(P2,0.5),pow(P3,0.33333333333334),P4);
	return 0;
}