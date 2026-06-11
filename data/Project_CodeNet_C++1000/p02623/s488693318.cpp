#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    ll a[n+5]={0},b[m+5]={0};
    for(ll i=1;i<=n;i++)
    {
    	 cin>>a[i];
	a[i]+=a[i-1];
    }
    for(ll i=1;i<=m;i++)
    {
    	 cin>>b[i];
	b[i]+=b[i-1];
    }
    for(ll i=0;i<=n;i++) 
	 if(k>=a[i]) ans=max(ans,upper_bound(b+1,b+1+m,k-a[i])-b-1+i);
    
	cout<<ans;
	return 0;
} 