#include "bits/stdc++.h"
using namespace std;

//43
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	//double ans = 0;
	sort(v.begin(),v.end());
	for (int i = 1; i  < n; ++i) {
		//ans += (v[i] + v[i - 1]) / 2.0;
		v[i] = (v[i] + v[i - 1]) / 2.0;
	}
	cout << fixed << setprecision(12) << v[n - 1];
}
