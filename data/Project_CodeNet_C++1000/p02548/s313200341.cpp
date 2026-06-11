#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

    ll mod_pow(ll a,ll b,ll m)
    {
        ll res=1;
        while(b)
        {
            if(b&1)
                res=(res*a)%m;

            a=(a*a)%m;
            b>>=1;
        }
        return res;
    }

void solve()
{
    ll n;
    cin>>n;
    vector<bool> vis(n,false);
    if(n<=2)
    {
        cout<<n-1;
        return;
    }
    ll ans=0;
    for(ll i=1;i<n;i++)
    {
       
        for(ll j=1;i*j<n;j++)
        {
            // cout<<i<<" "<<j<<endl;
                ans++;
        }
    }
    cout<<ans;
    return;
}

int main()
{
    FAST;
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r",stdin);
        freopen("output1.txt","w",stdout);
    #endif
    ll q;
    q=1;
    // cin>>q;
    while(q--)
        solve();
    return 0;
}
