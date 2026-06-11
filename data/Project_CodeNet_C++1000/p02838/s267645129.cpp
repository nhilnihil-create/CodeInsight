#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
int one[64];
int main() {
	int N; cin >> N;
	vector<ll> a(N); rep(i, N) cin >> a[i];
	ll ans = 0;
	rep(i, 60) {
		ll x = 0;
		rep(j, N) if (a[j]>>i & 1) x++;
		ll temp = x * (N-x) % MOD;
		rep(j, i) temp = temp * 2 % MOD;
		ans += temp;
		ans %= MOD;
	}
	cout << ans << endl;
}