#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;
int d[5005];
int cd[5005];
signed main() {
	int k, q; cin >> k >> q;
	rep(i, k)cin >> d[i];
	rep(Q, q) {
		int n, x, m; cin >> n >> x >> m;
		x %= m; n--;
		int sumd = 0;
		rep(i, k) {
			cd[i] = d[i] % m;
			if (!cd[i])cd[i] = m;
			sumd += cd[i];
		}
		int fin = x + sumd*(n / k);
		rep(i, n%k)fin += cd[i];
		fin /= m;
		cout << n - fin << endl;
	}
}