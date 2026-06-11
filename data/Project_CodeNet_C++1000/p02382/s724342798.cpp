#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int n;
int X[110],Y[110];
int main(){
	cin >> n;
	double sum = 0,sum2 = 0,sum3 = 0,m = 0;
	for(int i=0;i<n;i++){
		cin >> X[i];
	}
	for(int i=0;i<n;i++){
		cin >> Y[i];
	}
	for(int i=0;i<n;i++){
		sum += abs(X[i]-Y[i]);
		sum2 += abs(X[i]-Y[i])*abs(X[i]-Y[i]);
		sum3 += abs(X[i]-Y[i])*abs(X[i]-Y[i])*abs(X[i]-Y[i]);
		if(m < abs(X[i]-Y[i])) m = abs(X[i]-Y[i]);
	}
	printf("%.6f\n",sum);
	printf("%.6f\n",sqrt(sum2));
	printf("%.6f\n",cbrt(sum3));
	printf("%.6f\n",m);
}
