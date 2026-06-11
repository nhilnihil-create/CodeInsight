#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<double> X(n);
	vector<double> Y(n);
	double len;
	double D;
	double sum1 = 0.0;
	double sum2 = 0.0;
	double sum3 = 0.0;
	double D_inf = -1.0;
	double max =-1.0;

	for(int i=0; i<n; i++)
		cin >> X[i];
	for(int i=0; i<n; i++)
		cin >> Y[i];

	for(int i=0;i<n;i++){
		D = abs(X[i]-Y[i]);
		sum1 += D;
		sum2 += pow(D,2.0);
		sum3 += pow(D,3.0);
		if(D_inf<D)
			D_inf=D;
	}
	cout << fixed << setprecision(8) << sum1 << endl; 
	cout << fixed << setprecision(8) << sqrt(sum2) << endl;
	cout << fixed << setprecision(8) << pow(sum3, 1.0/3.0) << endl;
	cout << fixed << setprecision(8) << D_inf << endl;

	return 0;
}