#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int n, x; cin >> n >> x;
	vector<int> l(n);
	rep(i, n) cin >> l[i];
	vector<int> d(n + 1, 0);
	int ans = 0;
	for(int i = 0; i < n; i++) d[i + 1] = d[i] + l[i];
	rep(i, n + 1) if(d[i] <= x) ans++;
	cout << ans << endl;
}