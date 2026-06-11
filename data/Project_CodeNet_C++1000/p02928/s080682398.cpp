#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int mod = 1000000007;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a = v[i];
		ll l = 0;
		ll r = 0;
		for (int j = 0; j < n; j++) {
			if (j < i && v[j] > a) l++;
		 	if (v[j] > a) r++;
		}
		ans += l * k % mod;
		ans %= mod;
		ans += k * (k - 1) / 2 % mod * r % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}