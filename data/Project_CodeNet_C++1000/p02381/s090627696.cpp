#include<iostream>
#include<cmath> // sqrt???pow????????????????????????
#include<cstdio>
using namespace std;
 

int main() {
	int n=0;
	double *s;

	while(1){
		cin >> n;
		s = new double[n];
		if( n== 0 ) break;

		double sum=0;
		for(int i=0; i<n; i++){
			cin >> s[i];
			sum += s[i];
		}

		double m = sum / n;
		double x=0;

		for(int i=0; i<n; i++){
			x += (s[i]-m) * (s[i]-m);
		}

		double a = sqrt(x/n);
		printf("%.8f\n",a);
	}

	return 0;
}