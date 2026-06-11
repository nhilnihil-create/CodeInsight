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
	string s;
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < 1000; i++) {
		string t = to_string(i);
		while (t.size() < 3) t = '0' + t;
		int it = 0;
		for (int j = 0; j < n; j++) {
			if (it == 3) {
				break;
			}
			if (t[it] == s[j]) it++;
		}
		if (it == 3) ans++;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}