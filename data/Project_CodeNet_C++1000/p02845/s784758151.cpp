#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll mod = 1e9 + 7;
	int n;
	cin >> n;
	ll a,ans = 1;
	map<int, ll>mp;
	mp[-1] = 3;
	rep(i, n) {
		cin >> a;
		ans *= (mp[a - 1] - mp[a]);
		ans %= mod;
		mp[a]++;
	}
	cout << ans << endl;
	return 0;
}

