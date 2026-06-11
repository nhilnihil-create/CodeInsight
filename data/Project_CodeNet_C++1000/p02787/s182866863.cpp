#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > dp;

ll fun(vector<ll> &d,vector<ll> &p,ll h,ll n)
{
	if(h<=0)
	{
		return 0;
	}

	if(n==0)
	{
		ll temp=INT_MAX;
		return temp;
	}

	if(dp[n][h]!=-1)
	{
		return dp[n][h];
	}

	

	dp[n][h]=min(fun(d,p,h,n-1),p[n-1]+fun(d,p,h-d[n-1],n));
	return dp[n][h];

}


int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	
		ll h,n;
		cin>>h>>n;
		vector<ll> d(n);
		vector<ll> p(n);
		dp.resize(n+1,vector<ll>(h+1,-1));
		for(ll i=0;i<n;i++)
		{
			cin>>d[i];
			cin>>p[i];
		}
		

		cout<<fun(d,p,h,n)<<endl;


	
	return 0;
}