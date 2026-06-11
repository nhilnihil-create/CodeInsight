#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define at(x,i) get<i>(x);
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll m;cin >> m;
    ll ans=0;
    vl v;
    rep(i,m){
        ll a,n;cin >> a >>n;
        ll x;
        if(a==0){ans+=n-1;v.pb(0);}
        else{
            while(n){
                ll p=(10+a-1)/a;
                ans+=(p-1)*(n/p);
                rep(i,n%p)v.pb(a);
                ll v=a*p;
                v=v/10+v%10;
                ans+=n/p;
                n=n/p;
                a=v;
            }
        }
    }
    ll z=v[0];
    rep(i,v.size()-1){
        z+=v[i+1];
        ans++;
        if(z>9){
            z=z/10+z%10;
            ans++;
        }
    }
    cout << ans <<endl;
}
