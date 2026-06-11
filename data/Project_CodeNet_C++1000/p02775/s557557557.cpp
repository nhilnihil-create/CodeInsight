#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	int n = s.size();

	ll INF = 1e17;
	vector<vector<ll>> dp(n+1, vector<ll>(2, INF));
	dp[0][0] = 0;
	dp[0][1] = 1;

	rep(i, n){
		int x = s[i] - '0';
		chmin(dp[i+1][0], dp[i][0] + x);
		chmin(dp[i+1][1], dp[i][0] + (x + 1));
		chmin(dp[i+1][0], dp[i][1] + (10 - x));
		chmin(dp[i+1][1], dp[i][1] + (9 - x));
	}

	cout << dp[n][0] << endl;	
}
