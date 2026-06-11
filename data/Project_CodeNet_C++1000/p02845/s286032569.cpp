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
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	vector<int> cnt(3, 0);
	ll ans = 1;
	rep(i,n) {
		int c = 0;
		rep(j,3) {
			if (v[i] == cnt[j]) c++;
		}
		ans *= c;
		ans %= MOD;
		rep(j,3) {
			if (v[i] == cnt[j]) {
				cnt[j]++;
				break;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}