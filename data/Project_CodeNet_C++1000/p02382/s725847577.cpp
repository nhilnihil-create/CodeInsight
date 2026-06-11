#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
		int n;
		double D1 = 0,D2 = 0,D3 = 0,Dinf = 0;
		cin >> n;
		int x[n];
		int y[n];
		for(int i = 0;i < n;i++){
				cin >> x[i];
		}
		for( int i = 0;i < n;i++){
				cin >> y[i];
		}
		for( int i = 0;i < n;i++){
				D1 += abs(x[i] - y[i]);
				D2 += pow(x[i] - y[i],2);
				D3 += pow(abs(x[i] - y[i]),3);
		}
		D2 = sqrt(D2);
		D3 = pow(D3,1.0 /3.0);
		for( int i = 0;i < n;i++){
				if(Dinf < abs(x[i] -y[i])){
						Dinf = abs(x[i] - y[i]);
				}
		}
		printf("%f\n%f\n%f\n%f\n",D1,D2,D3,Dinf);
		return 0;
}