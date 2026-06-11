#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<double> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 0; i < n-1; ++i) {
		a[i+1]=(a[i] + a[i + 1]) / 2.0;
	}
	cout <<fixed<<setprecision(15)<< a[n - 1] << endl;
}