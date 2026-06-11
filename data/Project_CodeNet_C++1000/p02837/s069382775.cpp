#include<bits/stdc++.h>
#define ll long long int
#define vll vector<pair<ll, ll> >
#define vl vector<ll>
#define vi vector<int>
#define vii vector<pair<int, int> >
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
using namespace std;

ll power_mod(ll x, ll y, ll p)
{
	ll ans = 1;
	x = x%p;
	if(x==0)
	return p;

	while(y>0)
	{
		if(y&1)
		{
			ans = (ans*x)%p;
		}
		y = y>>1;
		x = (x*x)%p;
	}
	return ans;
} 

int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k,l,m,n;
	cin>>n;
	int a[20];
    int x[20][20];
    int y[20][20];
	
	for(i=1;i<=n;i++)
	{
	    cin>>a[i];
	    for(j=1;j<=a[i];j++)
	    {
	        cin>>x[i][j]>>y[i][j];
	    }
	}
	int ans = 0;
	for(j=1;j<(1<<n);j++)
	{
	    bool ok = true;
	    
	    for(i=1;i<=n;i++)
	    {
	        if(!(j & 1<<(i-1)))
	        {
	            continue;
	        }
	        
	        for(k=1;k<=a[i];k++)
	        {
	            if(((j >> (x[i][k]-1)) & 1) ^ y[i][k])
	            ok = false;
	        }
	    }
	    
	    if(ok)
	    ans = max(ans, counter(j));
	}
	cout<<ans<<"\n";
	return 0;
}
