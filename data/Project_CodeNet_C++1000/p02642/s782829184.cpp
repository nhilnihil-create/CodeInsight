#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> ors;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

ll lp[10000001];

void prime()
{
    repf(i,1,10000001) lp[i]=i;
    repf(i,2,10000001)
    {
        if(lp[i]==i)
        {
            for(ll j=2*i;j<10000001;j+=i)
            {
                if(lp[j]==j) lp[j]=i;
            }
        }
    }
}

ll w(ll a, ll b) {
    ll res=(b/2)*(a/2)+ceil((ld)b/2)*ceil((ld)a/2);
    return res;
}

ll W(ll a, ll b, ll c, ll d) {
    return w(c,d)-w(a-1,d)-w(c,b-1)+w(a-1,b-1);
}

ll B(ll a, ll b, ll c, ll d) {
    return (c-a+1)*(d-b+1)-W(a,b,c,d);
}

ll f[2000001];

void solve(ll tt) {
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) {
        cin>>a[i];
        f[a[i]]++;
    }
    sort(a,a+n);
    ll ans=0;
    repf(i,0,n) {
        bool pos=true;
        for(ll j=1;pos && j*j<=a[i];j++) {
            if(a[i]%j==0 && a[i]!=j) {
                if(f[j]) pos=false;
                if(j*j!=a[i] && j!=1) {
                    if(f[a[i]/j]) pos=false;
                }
            }
        }
        if(pos && f[a[i]]==1) ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    repf(tt,1,t+1) {
        solve(tt);
    }
}     