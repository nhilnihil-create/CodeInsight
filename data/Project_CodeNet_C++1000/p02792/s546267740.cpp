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

void solve() {
	int n;
	cin >> n;
	map<pii, ll> mp;
	for (int i = 1; i <= n; i++) {
		string p = to_string(i);
		int s = p[0] - '0';
		int t = p[p.size() - 1] - '0';
		mp[pii(s, t)]++;
	}
	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			ll a = mp[pii(i,j)];
			ll b = mp[pii(j,i)];
			ans += a * b;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}