#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
	
	int n,i;
	
	cin >> n;
	int x[n];
	for(i = 0; i < n; i++) cin >> x[i];
	int y[n];
	for(i = 0; i < n; i++) cin >> y[i];
	
	double d1;
	for(i = 0; i < n; i++){
		d1 += abs(x[i] - y[i]);
	}
	cout << fixed << setprecision(6) << d1 << endl;	
	
	double d2;
	for(i = 0; i < n; i++){
		d2 += abs(x[i] - y[i]) * abs(x[i] - y[i]);
	}
	d2 = sqrt(d2);
	cout << fixed << setprecision(6) << d2 << endl;
	
	double d3;
	for(int i = 0; i < n; i++){
		d3 += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
	}
	d3 = pow(d3, 1.0/3.0);
	cout << fixed << setprecision(6) << d3 << endl;	
	
	double d = abs(x[0] - y[0]);
	for(int i = 0; i < n-1; i++){
		d = max(d, abs(x[i+1] - y[i+1]));
	}
	cout << fixed << setprecision(6) << d << endl;
	
	return 0;
}