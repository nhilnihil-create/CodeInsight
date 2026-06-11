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
	int n, k;
	cin >> n >> k;
	int r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;
	ll ans = 0;
	for (int i = 0; i < k; i++) {
		char c = 'x';
		for (int j = i; j < n; j += k) {
			if (c == t[j]) c = 'x';
			else {
				if (t[j] == 'r') ans += p;
				else if (t[j] == 's') ans += r;
				else ans += s;
				c = t[j];
			}
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}