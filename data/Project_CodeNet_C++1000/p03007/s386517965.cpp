#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define MP make_pair
#define F first
#define S second
#define sz(v) (ll)v.size()
#define inf 1000000000000000000
#define vll vector<ll>
using namespace std;
const int N=100005;

void solve()
{
	ll n,a[N],i,ans,pre1,pre2;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ans=-a[0]+a[n-1];
	for(i=1;i<n-1;i++)
		ans+=abs(a[i]);
	cout<<ans<<"\n";
	pre1=a[n-1];
	for(i=1;i<n-1;i++)
	{
		if(a[i]<0)
		{
			cout<<pre1<<" "<<a[i]<<"\n";
			pre1-=a[i];
		}
		else
			break;
		
	}
	pre2=a[0];
	for(i=n-2;i>0;i--)
		if(a[i]>=0)
		{
			cout<<pre2<<" "<<a[i]<<"\n";
			pre2-=a[i];
		}
	cout<<pre1<<" "<<pre2<<"\n";
}
 
int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    
    return 0;
}