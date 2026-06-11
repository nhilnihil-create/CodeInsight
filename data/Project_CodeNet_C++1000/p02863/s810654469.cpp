/*
author : seryu
title : ABC145E_"All-you-can-eat"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	int n, t; cin >> n >> t;
	vector<P> dishes(n);
	rep(i, n)cin >> dishes[i].first >> dishes[i].second;
	sort(all(dishes));
	vector<vector<int>> dp(n+1, vector<int>(t, 0));
	int ans = 0;
	rep(i, n)
	{
		rep(j, t)
		{
			chmax(dp[i+1][j],dp[i][j]);
			if(j - dishes[i].first >= 0)chmax(dp[i+1][j], dp[i][j - dishes[i].first] + dishes[i].second);
		}
		chmax(ans, dp[i][t-1] + dishes[i].second);
	}
	cout << ans << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
