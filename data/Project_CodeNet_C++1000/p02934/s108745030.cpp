#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int n; cin >> n;
	vector<long double> a(n);
	rep(i, n) cin >> a[i];
	long double ans = 0.0;
	rep(i, n){
		ans += (1.0 / a[i]);
	}
	ans = 1.0 / ans;
	cout << setprecision(10) << ans << endl;
}