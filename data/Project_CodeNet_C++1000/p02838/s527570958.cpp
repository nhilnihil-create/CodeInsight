#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	    cin>>a[i];
	ll cnt[64],ans=0,p=1;

    for(ll i=0;i<64;i++)
        cnt[i]=0;
    for(ll i=0;i<n;i++)
    {
        ll c=0;
        while(a[i]>0)
        {
            cnt[c]+=a[i]%2;
            a[i]/=2;
            c++;
        }
    }
  
    for(ll i=0;i<64;i++)
    {
        p=pow(2,i);
        p%=MOD;
        ans+=((((n-cnt[i])*cnt[i])%MOD)*p%MOD);
        ans%=MOD;
  }
  cout<<ans;
    return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
