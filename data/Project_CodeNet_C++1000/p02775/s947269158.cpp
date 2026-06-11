#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

ll dp[1000005][2];

int main(){	
	string N;
	cin >> N;
	ll res = 0;
	dp[0][1] = INF;
	int n = N.size();
	rep(i, n) {
		ll c = N[n-1-i]-'0';
		if (c != 9) dp[i+1][0] = min(dp[i][0]+c, dp[i][1]+c); else dp[i+1][0] = dp[i][0]+c; 
		dp[i+1][1] = min(dp[i][0]+10-c+1, dp[i][1]+9-c);
		// cout << i+1 << ": " << dp[i+1][0] << " " << dp[i+1][1] << endl;
	}
	
	cout << min(dp[n][0], dp[n][1]) << endl;
	return 0;
}

