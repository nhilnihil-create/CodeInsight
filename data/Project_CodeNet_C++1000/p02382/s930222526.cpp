#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	double *x;
	double *y;
	x = new double[n];
	y = new double[n];

	for(int i=0; i<n; i++) cin >> x[i];
	for(int i=0; i<n; i++) cin >> y[i];

	double d[4]={};
	for(int p=1; p<=3; p++){
		for(int i=0; i<n; i++){
			d[p] += pow(fabs(x[i]-y[i]),p);
		}
		d[p] = pow(d[p],1.0/p);
	}


	for(int i=0; i<n; i++){
		if(d[0]<fabs(x[i]-y[i])){
			d[0]=fabs(x[i]-y[i]);
		}
	}

	printf("%.5f\n",d[1]);
	printf("%.5f\n",d[2]);
	printf("%.5f\n",d[3]);
	printf("%.5f\n",d[0]);


    return 0;
}