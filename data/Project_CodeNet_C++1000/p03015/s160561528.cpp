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
	
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	dp[0][0] = 1;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < 2; i++) {
			if(i) {
				dp[k + 1][i] += 3 * dp[k][i];
			} else {
				if(s[k] == '0') {
					dp[k + 1][i] += dp[k][i];
				} else {
					dp[k + 1][i + 1] += dp[k][i];
					dp[k + 1][i] += 2 * dp[k][i];
				}
			}
			
			dp[k + 1][i] %= P;
			dp[k + 1][i + 1] %= P;
		}
	}
	
	cout << (dp[n][0] + dp[n][1]) % P << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}