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
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> ans(n);
	rep(i,n) {
		if (i % 2 == 0) ans[0] += a[i];
		else ans[0] -= a[i];
	}
	rep(i,n-1) {
		ans[i + 1] = 2 * a[i] - ans[i]; 
	}
	rep(i,n) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	solve();
	return 0;
}