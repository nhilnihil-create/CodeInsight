
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define inp(x) cin>>x
#define print(x) cout<<x
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define reset(d,val) memset(d,val,sizeof(d))
#define sort(v) sort(v.begin(),v.end())
#define sort_arr(arr,i,f) sort(arr+i,arr+f)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 998244353;

ll dp[3002][3002];
int arr[3002];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,s;
	cin>>n>>s;
	dp[0][0] = 1;
	for (int i = 1; i <=n; ++i)
	{
		cin>>arr[i];
		for(int j=0;j<=s;j++) {
			dp[i][j] = (2*dp[i-1][j])%mod;
			if(j-arr[i]>=0) dp[i][j] = (dp[i][j]+dp[i-1][j-arr[i]])%mod;
			//if(dp[i][j]>=mod) dp[i][j]-=mod;
		}
	}
	cout<<(dp[n][s]+mod)%mod;
	return 0;
}

