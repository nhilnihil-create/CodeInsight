#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double D1 = 0,D2 = 0,D3 = 0,Di = 0;
	cin >> n;
	int x[n],y[n];
	for(int i = 0;i < n;i++) cin >> x[i];
	for(int i = 0;i < n;i++) cin >> y[i];
	
	for(int i = 0;i < n;i++){
		if(x[i] - y[i] < 0) D1 += y[i] - x[i];
		else D1 += x[i] - y[i];
	}
	
	for(int i = 0;i < n;i++){
		D2 += (x[i] - y[i]) * (x[i] - y[i]);
	}
	D2 = sqrt(D2);
	
	for(int i = 0;i < n;i++){
		if(x[i] - y[i] < 0) D3 += pow((y[i] - x[i]),3);
		else D3 += pow((x[i] - y[i]),3);
	}
	
	D3 = pow(D3,1/3.0);
	
	for(int i = 0;i < n;i++){
		if(x[i] - y[i] < 0){
			if(Di < y[i] - x[i]) Di = y[i] - x[i];
			}else{
				if(Di < x[i] - y[i]) Di = x[i] - y[i];
			}
	}
			
	printf("%5lf\n%5lf\n%5lf\n%5lf\n",D1,D2,D3,Di);
				return 0;
	}