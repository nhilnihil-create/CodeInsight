#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define nl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pi;

void solve()
{
	int n;
	cin>>n;
	vector<pi> a(n);
	for(int i=0; i<n; i++)
	{
		cin>>a[i].F;
		a[i].S = i;
	}
	sort(a.begin(), a.end(), greater<pi>());
	ll dp[n+1][n+1];
	dp[0][n] = 0;
	for(int i=0; i<n; i++)
	{
		ll act = a[i].F;
		int pos = a[i].S;
		dp[0][n-1-i] = dp[0][n-i] + act*abs(n-1-i-pos);
		dp[i+1][n] = dp[i][n] + act*abs(pos-i);
		for(int j=1; j<i+1; j++)
		{
			int k = n-i-1+j;
			dp[j][k] = max(dp[j][k+1] + act*abs(k-pos), dp[j-1][k] + act*abs(pos-j+1));
		}
		
	}
	ll ma = 0;
	for(int i=0; i<=n; i++)
		ma = max(ma, dp[i][i]);
	cout<<ma<<nl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}
