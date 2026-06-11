#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> Name(n, vector<Type>(m, d))
#define P pair
using namespace std;
using ll = long long;

const int INF = 1e8;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	rep(i,n) cin >> a[i];
	

	int ans = -1;
	int tmp = 0;
	int cnt = 1;
	rep(i, n) {
		if (a[i] == cnt) {
			if (ans == -1) ans = tmp;
			else ans += tmp;
			tmp = 0;
			cnt += 1;
		}
		else tmp++;
	}

	if (ans == -1) cout << -1 << endl;
	else cout << ans + tmp << endl;

	return 0;
}
