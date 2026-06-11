#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
		ll n,l,cnt=0;
		cin>>n>>l;
        // ll cnt=0;
        for(ll i=1;i<=n;i++){
                cnt+=l+i-1;
        }
        if(n==1){
                cout<<0<<endl;
                return;
        }
        ll ans=-100000;
        for(ll i=1;i<=n;i++)
        {
                ll c=cnt-l+1-i;
                if(abs(c-cnt)<abs(cnt-ans)){
                        ans=c;
                }
        }
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