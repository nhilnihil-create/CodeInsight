#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
typedef long long ll;
int n,d;
bool isInt(long double p) {
	return fabs(p-floor(p)) <= eps;
}
long double dist(vector<long double>&a, vector<long double>&b) {
	long double di = 0;
	for (int i=0; i<d; i++) {
		di += (fabs(a[i]-b[i]))*(fabs(a[i]-b[i]));
	}
	return sqrtf(di);
}
int main() {
	cin >> n >> d;
	vector< vector< long double > > a(n, vector<long double>(d));
	for (int i=0; i<n; i++) {
		for (int j=0; j<d; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			long double di = dist(a[i],a[j]);
			// cout << i << ' ' << j << ' ' << di << '\n';
			if (isInt(di)) {
				ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
}
