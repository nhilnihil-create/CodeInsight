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

const int D = 60;
const int MAX_N = 200005;
int to[D][MAX_N];

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i,n) {
		to[0][i] = a[i];
	}
	rep(i,D - 1) {
		rep(j, n) {
			to[i+1][j] = to[i][to[i][j]];
		}
	}
	int cur = 0;
	for (int i = D - 1; i >= 0; i--) {
		ll p = 1ll << i;
		if (k < p) continue;
		// cout << p << " " << cur << endl;
		cur = to[i][cur];
		k -= p;
	}
	cout << cur + 1 << endl;
}

int main() {
	solve();
	return 0;
}