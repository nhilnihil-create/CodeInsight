#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	double r1,r2,r3,rinf;
	int a[1000],b[1000],c[1000];
	int n;
	r1 = 0;
	r2 = 0;
	r3 = 0;
	rinf = 0;
	cin >>n ;
	for(int i = 0 ; i < n; i++){
		cin >>  a[i];
	}
	for (int i = 0 ; i < n ;i++){
		cin >> b[i];
	}
	for(int i = 0; i < n ; i++){
		c[i] = a[i]-b[i];
		r1 += abs(c[i]);
		r2 += c[i]*c[i];
		r3 += abs(c[i]*c[i]*c[i]);
		if(rinf<abs(c[i])){
			rinf = abs(c[i]);
		}
	}
	r2 = sqrt(r2);
	r3 = pow(r3,(double)1/(double)3);
	printf("%.8f\n%.8f\n%.8f\n%.8f\n",r1,r2,r3,rinf);
	return 0;
}