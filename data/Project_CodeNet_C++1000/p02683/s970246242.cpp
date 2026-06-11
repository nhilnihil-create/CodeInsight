#include<bits/stdc++.h>
#define ll  long long int
#define loop(i,a,b) for(i=a;i<b;i++)
#define mod 100000007
#define INF 1000000000000
#define pb push_back
#define lim 500001
using namespace std;

char opposite(char x)
{
	if(x=='0')
		return '1';
	else
		return '0';
}

ll power(ll x,ll y)
{
	ll res=1;

	while(y){
		if(y%2)
			res=(res*x)%mod;
		x=(x*x)%mod;
	}

	return res;
}
int main()
{
	ll i,j,k,n,m,x,ans=INF;

	cin>>n>>m>>x;

	ll lev[n+1][m+1],cost[n+1];

	loop(i,0,n)
	{
		cin>>cost[i];

		loop(j,0,m) cin>>lev[i][j];
	}

	ll last=(1<<n);

	loop(i,0,last)
	{ll tot=0;
		vector<ll> temp(m,0);
		loop(j,0,n)
		{
			if((i>>j)&1)
			{
				tot+=cost[j];

				loop(k,0,m)
				temp[k]+=lev[j][k];
			}
		}

		loop(j,0,m)
		if(temp[j]<x)
			break;

		if(j==m){
		    ans=min(ans,tot);
		}}

		if(ans==INF) ans=-1;

		cout<<ans<<endl;
		return 0;
	}
