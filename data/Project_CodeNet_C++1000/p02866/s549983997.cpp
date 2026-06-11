#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const ll M = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> c(n);
	rep(i,n) cin >> v[i];

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i]);
		c[v[i]]++;
	}
	if (c[0] != 1 || v[0] != 0) {
		cout << 0 << endl;
		return;
	}

	ll ans = 1;
	for (int i = 0; i <= mx; i++) {
		int k = c[i+1];
		ll temp = 1;
		for (int j = 0; j < k; j++) {
			temp *= c[i];
			temp %= M;
		}
		ans *= temp;
		ans %= M;
	}
	cout << ans << endl;
} 

int main() {
	solve();
	return 0;
}