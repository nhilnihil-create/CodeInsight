#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define forn(i,n) for(int i=0; i<(int)n; i++)
ll power(ll x,ll n);
bool isprime(ll n);


void test_case()
{
    ll n,m,a,b;
    cin>>n>>m;
    ll height[n+1];
    for(ll i=1;i<=n;i++)
        cin>>height[i];
    vector<ll> adj[n+1];
    while(m--) {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll cnt=0;
    for(ll i=1;i<=n;i++) {
            bool f=1;
        for(ll x:adj[i]) {
            if(height[x]>=height[i]) {
                f=0;
                break;
            }
        }
        if(f)
            cnt++;
    }
    cout<<cnt;


}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
ll power(ll x,ll n)
{
    ll ans=1;
    while(n>0) {
        if(n&1)
            ans*=x;
        n>>=1;
        x*=x;
    }
    return ans;
}

bool isprime(ll n)
{
    if(n==2 || n==3)
        return true;
    if(n<=1 || n%2==0 || (n%6!=1 && n%6!=5))
        return false;
    for(ll i=3;i*i<=n;i+=2) {
        if(n%i==0)
            return false;
    }
    return true;
}
