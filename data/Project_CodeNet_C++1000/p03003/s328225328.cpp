#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const ll MOD = 1e9+7;
const int MAX_N = 2050;

int n, m;
int s[MAX_N];
int t[MAX_N];
ll dp[MAX_N][MAX_N];
ll sum[MAX_N][MAX_N];

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("in.txt", "r", stdin);

	cin >> n >> m;
	rep(i,0,n) {
		cin >> s[i];
	}
	rep(i,0,m) {
		cin >> t[i];
	}
	rep(i,0,MAX_N) rep(j,0,MAX_N) {
		dp[i][j] = 0LL;
		sum[i][j] = 0LL;
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i-1] == t[j-1]) {
				dp[i][j] = (sum[i-1][j-1] + 1) % MOD;
			}
			sum[i][j] = (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + MOD) % MOD;
		}
	}

	cout << (sum[n][m]+1) % MOD << endl;
	return 0;
}
