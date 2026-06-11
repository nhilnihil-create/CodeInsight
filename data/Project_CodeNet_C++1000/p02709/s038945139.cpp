#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T>inline bool chmax(T& a, T b) { if (a <= b) { a = b; return true; } else return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }


int main() {
	ll n; cin >> n;
	vector<pair<ll,ll>> a(n);
	rep(i,n) { cin >> a[i].first; a[i].second = i;}

	sort(all(a), greater<pair<ll,ll>>());

	vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));

	rep1(k, n) rep(i, n+1) {
	  int j = k - i;
	  if (0 <= i-1 && 0 <= j && j <= n) chmax(dp[i][j], dp[i-1][j] + a[k-1].first*(a[k-1].second-i+1));
		if (0 <= j-1 && j <= n) chmax(dp[i][j], dp[i][j-1] + a[k - 1].first * (n-j - a[k-1].second));
	}

	ll ans = 0;
	rep(i,n+1) chmax(ans, dp[i][n-i]);
	cout << ans << endl;
}