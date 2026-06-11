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
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        ll d1,d2;
        cin>>d1>>d2;
        if(d1==d2)
            cnt++;
        else
            cnt=0;
        if(cnt==3)
        {
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
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
