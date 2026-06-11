#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
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
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
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
vl topsort(vvl &g){
    ll n=g.size();
    vl ans,ind(n);
    rep(i,n)for(auto e:g[i])ind[e]++;
    queue<ll> que;
    rep(i,n)if(!ind[i])que.push(i);
    while(!que.empty()){
        ll v=que.front();que.pop();
        ans.pb(v);
        for(auto nv:g[v]){
            ind[nv]--;if(!ind[nv])que.push(nv);
        }
    }
    return ans;
}
int main(){
    ll n,m;cin >> n >>m;
    vvl g(n);rep(i,m){
        ll a,b;cin >> a >> b;
        g[a].pb(b);
    }
    vl ans=topsort(g);
    for(auto p:ans)cout << p <<endl;
} 
