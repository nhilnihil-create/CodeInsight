#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> dis;
    vector<ll> plus,minus;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        plus.push_back(x+y);
        minus.push_back(x-y);

    }
    sort(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());

    cout<<max((plus[n-1]-plus[0]),(minus[n-1]-minus[0]));
    return;
}

int main()
{
    FAST;
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif
    ll q;
    q=1;
    // sieve();
    // cin>>q;
    while(q--)
        solve();
    return 0;
}
