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

const ll mod=1e9+7;

struct LazySegmentTree{
private:
    ll n;
    vector<ll> node, lazy;
public:
    LazySegmentTree(vector<ll> v){
        ll sz=(ll)v.size();
        n=1;
        while(n<sz) n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1,0);
        rep(i,sz) node[i+n-1]=v[i];
        for(ll i=n-2;i>=0;i--) node[i]=node[2*i+1]+node[2*i+2];
    }
    void eval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            node[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k]/2;
                lazy[2*k+2]+=lazy[k]/2;
            }
            lazy[k]=0;
        }
    }
    void add(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
        if(r<0) r=n;
        eval(k,l,r);
        if(b<=l || r<=a) return;
        if(a<=l && r<=b){
            lazy[k]+=(r-l)*x;
            eval(k,l,r);
        }
        else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=node[2*k+1]+node[2*k+2];
        }
    }
    ll getsum(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r<0) r=n;
        if(b<=l || r<=a) return 0;
        eval(k,l,r);
        if(a<=l && r<=b) return node[k];
        ll vl=getsum(a,b,2*k+1,l,(l+r)/2);
        ll vr=getsum(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
};

int main()
{
    ll n,d,a;
    cin >> n >> d >> a;
    vector<pll> x(n);
    LazySegmentTree seg=LazySegmentTree(vector<ll>(n+1));
    rep(i,n){
        cin >> x[i].fi >> x[i].se;
    }
    sort(x.begin(),x.end());
    vector<ll> xx(n);
    
    rep(i,n){
        xx[i]=x[i].fi;
        seg.add(i,i+1,x[i].se);
    }
    ll ans=0;
    rep(i,n){
        if(seg.getsum(i,i+1)<=0) continue;
        auto it=upper_bound(xx.begin(),xx.end(),xx[i]+2*d)-xx.begin();
        ll val=seg.getsum(i,i+1);
        ll times=(val-1)/a+1;
        seg.add(i,it,-times*a);
        ans+=times;
    }
    cout << ans << endl;
    return 0;
} 
