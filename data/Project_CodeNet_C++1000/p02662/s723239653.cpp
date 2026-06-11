#include<bits/stdc++.h>
using namespace std;

#define double      long double
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define endl        "\n"
#define repp(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5 + 5;
const int MOD=998244353;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int32_t main()
{
	IOS;
	//memset(dp,-1,sizeof(dp));	
	int T;
	T = 1;
	while(T--)
	{
		int n,s;
		cin >> n;
		cin >> s;
		int dp[n+1][s+1];
		memset(dp,0,sizeof(dp));
		int inv2 = modinv(2);
		dp[0][0] = pow(2,n,MOD);
		int a[n];
		rep(i,0,n-1)
		{
			cin >> a[i];
		}
		repp(i,0,n)
		{
			repp(j,0,s+1)
			{
				dp[i+1][j] = (dp[i+1][j] +  dp[i][j])%MOD;
				if(j+a[i]<=s)
					dp[i+1][j+a[i]]  = (dp[i+1][j+a[i]] + dp[i][j]*inv2)%MOD;
			}
		}
		cout << dp[n][s] << endl;
	}
}
