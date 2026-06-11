#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	
	int n,i;
	double p1=0, p2=0, p3=0, pm=0;
	cin >> n ;
	
	int x[n], y[n], dif[n];
	for (i=0; i<n; i++){
		cin >> x[i] ;		
	}
	for (i=0; i<n; i++){
		cin >> y[i] ;		
	}	
	for (i=0; i<n; i++){
		dif[i]=fabs(x[i]-y[i]);
		p1+=dif[i];
		p2+=pow(dif[i], 2);
		p3+=pow(dif[i], 3);
		if (pm<dif[i]) pm=dif[i];
	}
	p2=sqrt(p2);
	p3=pow(p3, 1.0/3.0);
	
	printf("%.6f\n""%.6f\n""%.6f\n""%.6f\n", p1, p2, p3, pm);
	
	return 0;
}