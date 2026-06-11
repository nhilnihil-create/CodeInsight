#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld double 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define BOOST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define sl(a) a.size()
#define mod 1000000007 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define MAX1 100006
#define f first
#define s second
#define pi 2*acos(0.0)
bool compare(pair<ll,ll> &p1, pair<ll,ll> &p2)
{
    return p1.s<p2.s;
}
void solve()
{
    ll n;  cin>>n;
    vector<pair<ll,ll>> vp;
    rep(i,0,n)
    {
        ll x,y; cin>>x>>y;
        vp.pb({x,y});
    }
    sort(all(vp),compare);
    ll ans=0,last=0;
    rep(i,0,n)
    {   
        if(last+vp[i].f<=vp[i].s) 
        {
            ans++;
            last+=vp[i].f;
        }
    }cout<<(ans==n?"Yes":"No");
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt","r",stdin);
    //for getting error from error.txt
    freopen("error.txt", "w", stderr);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
    #endif
    BOOST
    int T=1;  //cin>>T;
    while(T--) solve();
    cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    cerr<<"My CLOCKS_PER_SEC= "<<CLOCKS_PER_SEC<<"\n";
    return 0;
}
