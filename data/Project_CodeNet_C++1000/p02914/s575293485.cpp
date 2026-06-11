#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;


int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n),top(n);
    ll s=0;
    rep(i,n){
        cin >> a[i];
        s^=a[i];
    }
    rep(i,n){
        a[i] &= ~s;
    }
    ll r=0;
    for(ll i=60;i>=0;i--){
        ll j=r;
        for(;j<n;j++){
            if(a[j]>>i&1){
                swap(a[j],a[r]);
                break;
            }
        }
        if(j==n) continue;
        top[r]=i;
        rep(k,n){
            if(k==r) continue;
            if(a[k]>>i&1){
                a[k]^=a[r];
            }
        }
        r++;
    }
    ll ans=s;
    ll x=0;
    for(ll i=60;i>=0;i--){
        ll nx=x|(1ll<<i);
        ll b=nx;
        rep(j,r){
            if(b>>top[j]&1) b^= a[j];
        }
        if((b&nx)==0) x=nx;
    }
    ans+=2*x;
    cout << ans << endl;
    return 0;
} 
