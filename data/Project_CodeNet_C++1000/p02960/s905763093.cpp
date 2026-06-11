#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

ll dp[100001][13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	dp[0][0] = 1;
	rep(i, n) {
		int c = -1;
		if (s[i] != '?') c = s[i] - '0';
		rep(j, 10) {
			if (c != -1 && j != c) continue;
			rep(k, 13) {
				(dp[i + 1][(k * 10 + j) % 13] += dp[i][k]) %= mod;
			}
		}
	}
	cout << dp[n][5] % mod << endl;
	return 0;
}