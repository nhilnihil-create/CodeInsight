#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int n, l; cin >> n >> l;
	vector<int> a(n);
	rep(i, n) a[i] = l + i;
	int ans = 0;
	rep(i, n) ans += a[i];
	vector<int> b(n);
	rep(i, n) b[i] = ans - a[i];
	rep(i, n) b[i] = abs(ans - b[i]);
	int id = min_element(b.begin(), b.end()) - b.begin();
	//rep(i, n) cout << b[i] << " ";
	cout << ans - a[id] << endl;
}