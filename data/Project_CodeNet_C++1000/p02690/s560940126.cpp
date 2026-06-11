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

ll f(ll k) {
	return k * k * k * k * k;
}

void solve() {
	ll x;
	cin >> x;
	vector<ll> v(201);
	for (ll i = 0; i <= 200; i++) {
		v[i] = f(i);
	}
	for (ll i = 0; i <= 200; i++) {
		for (ll j = 0; j <= 200; j++) {
			if (v[i] - v[j] == x) {
				cout << i << " " << j << endl;
				return;
			}
			if (v[i] + v[j] == x) {
				cout << i << " " << -j << endl;
				return;
			}
		}
	}
}

int main() {
	solve();
	return 0;
}