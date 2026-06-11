#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;


ll dp[2005][2005];



int main() {

	ll n, m;
	cin >> n >> m;

	ll ans = 0;

	dp[0][0] = 1;

	VI s(n);
	VI t(m);
	REP(i, n)cin >> s[i];
	REP(i, m)cin >> t[i];
	REP(i, 2005) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}

	REP(i, n) {
		REP(j, m) {
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
			if (s[i] == t[j])dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j + 1] += mod;
			dp[i + 1][j + 1] %= mod;
		}
	}


	cout << dp[n][m] << endl;



}


