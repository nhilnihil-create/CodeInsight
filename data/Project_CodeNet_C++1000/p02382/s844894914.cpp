#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

int main(){
	    cout<< fixed
         << setprecision(10)
         << endl;
	int n;
	double x[100], y[100], ans = 0.0;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> x[i];
	}
	for(int i=0;i<n;++i){
		cin >> y[i];
	}

	for(int i=0;i<n;++i){
		ans += abs(x[i] - y[i]);
	}
	cout << ans << endl;

	ans = 0.0;
	for(int i=0;i<n;++i){
		ans += pow(abs(x[i] - y[i]), 2.0);
	}
	ans = pow(ans, 1.0/2.0);
	cout << ans << endl;

	ans = 0.0;
	for(int i=0;i<n;++i){
		ans += pow(abs(x[i] - y[i]), 3.0);
	}
	ans = pow(ans, 1.0/3.0);
	cout << ans << endl;

	ans = 0.0;
	for(int i=0;i<n;++i){
		if(abs(x[i] - y[i]) > ans){
			ans = abs(x[i] - y[i]);
		}
	}
	cout << ans << endl;
}