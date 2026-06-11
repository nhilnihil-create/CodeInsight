#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,sa;
	double D = 0;
	cin>>n;
	int x[n];
	int y[n];
	for(int i = 0;i<n;i++){
		cin>>x[i];
	}
	for(int i = 0;i<n;i++){
		cin>>y[i];
	}
	for(int i = 0;i<n;i++){
		if(x[i]>y[i])sa = x[i] - y[i];
		else  sa = y[i] -x[i];
		D += sa;
	}
	printf("%.4f\n",D);
	sa = 0;
	D = 0;
	for(int i = 0;i<n;i++){
		if(x[i]>y[i])sa = x[i] - y[i];
		else  sa = y[i] -x[i];
		D += sa*sa;
	}
	printf("%.10f\n",sqrt(D));
	D = 0;
	sa = 0;
	for(int i = 0;i<n;i++){
		if(x[i]>y[i])sa = x[i] - y[i];
		else  sa = y[i] -x[i];
		D += sa*sa*sa;
	}
	printf("%.10f\n",cbrt(D));
	D = 0;
	sa = 0;
	float max = 0;
	for(int i = 0;i<n;i++){
		if(x[i]>y[i])sa = x[i] - y[i];
		else  sa = y[i] -x[i];
		if(max<sa)max = sa;
	}
	printf("%.4f",max);
	return 0;
}
