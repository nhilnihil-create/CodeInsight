
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}


int main()
{
	fastio;
	ll dp[2010]={0};
	ll n,x,y;
	cin>>n>>x>>y;
	ll i,j,k;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			ll mi=min(abs(x-j)+1+abs(i-y),i-j);
			dp[mi]++;
		}
	}
	for(i=1;i<=n-1;i++)
		cout<<dp[i]<<endl;

    return 0;
}



