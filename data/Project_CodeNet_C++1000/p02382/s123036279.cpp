#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
 
int main () {
	int n,i;
	double sum1=0,sum2=0,sum3=0,sum=0;
	cin >> n;
	double x[n],y[n],z[n];
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	for(i=0;i<n;i++){
		cin >> y[i];
	}
	for(i=0;i<n;i++){
		z[i]=abs(x[i]-y[i]);
	}
	for(i=0;i<n;i++){
		sum1+=z[i];
	}
	for(i=0;i<n;i++){
		sum2+=z[i]*z[i];
	}
	sum2=sqrt(sum2);
	for(i=0;i<n;i++){
		sum3+=z[i]*z[i]*z[i];
	}
	sum3=pow(sum3,1/3.0);
	for(i=0;i<n;i++){
		if(z[i]>sum) sum=z[i];
	}
	cout << setprecision(20)<< sum1 << endl << sum2 << endl << sum3 << endl << sum << endl;
	return 0;
}
	