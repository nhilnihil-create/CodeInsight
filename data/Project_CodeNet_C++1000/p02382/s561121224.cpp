#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	double d1=0, d2=0, d3=0, di=0, temp;
	vector<double> v1, v2;
	int n;
	cin >> n;
	v1.resize(n);
	v2.resize(n);
	for(int i=0; i<n; ++i) {
		cin >> v1[i];
	}
	for(int i=0; i<n; ++i) {
		cin >> v2[i];
	}
	for(int i=0; i<n; ++i) {
		temp=abs(v1[i]-v2[i]);
		d1+=temp;
		d2+=temp*temp;
		d3+=temp*temp*temp;
		di=(di>temp?di:temp);
	}
	cout << fixed << setprecision(6);
	cout << d1 << endl;
	cout << pow(d2,1.0/2.0) << endl;
	cout << pow(d3,1.0/3.0) << endl;
	cout << di << endl;

	return 0;
}