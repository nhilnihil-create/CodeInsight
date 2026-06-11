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
	ll i,n,k;

	cin>>n>>k;
	ll a[n+1];


	loop(i,1,n+1) cin>>a[i];

	vector<ll> vis(n+1,0),ans;

	ans.pb(1);
	vis[1]=1;
	ll curr=a[1];

	while(!vis[curr])
	{
	    vis[curr]=1;
		ans.pb(curr);
		curr=a[curr];
	}
	ll len=ans.size();
	
	loop(i,0,len)
	if(ans[i]==curr)
	break;
	
    if((k+1)<=len)
    {
        cout<<ans[k]<<endl;
        return 0;
    }
    k-=i;

    cout<<ans[k%(len-i)+i]<<endl;
    
	return 0;}

