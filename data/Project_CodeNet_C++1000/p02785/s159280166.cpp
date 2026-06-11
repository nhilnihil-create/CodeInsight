#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int a = max(n - k,0);

	sort(h.begin(), h.end());
	ll ans = 0;
	rep(i, a) ans += h[i];

	cout << ans << endl;
	return 0;
}
