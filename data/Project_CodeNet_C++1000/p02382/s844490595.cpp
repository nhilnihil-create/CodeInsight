#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

double dabs(double a){
	if (a>0) return a;
	else return -a;
}

int main(){
	int n;
	int x[1000],y[1000];
	double D1=0,D2=0,D3=0,Dm=0;
	cin >> n;
	
	for (int i = 0; i < n; i++)	cin >> x[i];
	for (int i = 0; i < n; i++)	cin >> y[i];
	
	
	for (int i = 0; i < n; i++){	
		D1 += dabs(x[i]-y[i]);
		D2 += pow(dabs(x[i]-y[i]),2);
		D3 += pow(dabs(x[i]-y[i]),3);
		Dm = Dm < dabs(x[i]-y[i]) ? dabs(x[i]-y[i]):Dm;
	}
	
	printf("%.8f\n",D1);	
	printf("%.8f\n",sqrt(D2));
	printf("%.8f\n",pow(D3,1.0/3.0));
	printf("%.8f\n",Dm);
	return 0;
}