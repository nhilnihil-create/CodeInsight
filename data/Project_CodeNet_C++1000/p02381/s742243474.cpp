#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

double STD(int n){
	double s[1000] = {0.0};
	double m = 0.0;
	double sum = 0.0;
	double sigma2 = 0;
	for(int i = 0; i < n; i++){
		cin>>s[i];
		sum += s[i];
	}
	m = sum / n;
	for(int i = 0; i < n; i++){
		sigma2 += (s[i] - m)*(s[i] -m);
	}
	sigma2 = sigma2 / n;
	return sqrt(sigma2);
}


int main()
{
	int n;
	cin>>n;
	while(n != 0){
		double std = STD(n);
		printf("%0.8lf\n",std);
		cin>>n;
	}
	return 0;
}