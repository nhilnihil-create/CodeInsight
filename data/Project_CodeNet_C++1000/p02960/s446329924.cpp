#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	string s;
	cin >> s;
	
	int n = s.length();
	vvi dp(n + 1, vi(13, 0));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		if(s[i] == '?') {
			for(int j = 0; j < 13; j++) {
				for(int k = 0; k < 10; k++) {
					(dp[i + 1][(10 * j + k) % 13] += dp[i][j]) %= P;
				}
			}
		} else {
			for(int j = 0; j < 13; j++) {
				(dp[i + 1][(j * 10 + (s[i] - '0')) % 13] += dp[i][j]) %= P;
			}
		}
	}
	
	cout << dp[n][5] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}