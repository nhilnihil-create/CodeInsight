#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
		ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x=b-a+1;
        ll ans=x;
        ans-=(b/c-(a-1)/c);
        ans-=(b/d-(a-1)/d);
        ll lm=lcm(c,d);
        ans+=(b/lm - (a-1)/lm);
        cout<<ans<<endl;    
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