#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
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
    ll n,m;cin >> n >>m;
    vvl g(3*n);
    rep(i,m){
        ll a,b;cin >> a >>b;
        a--;b--;
        g[a].pb(b+n);
        g[a+n].pb(b+n+n);
        g[a+n+n].pb(b);
    }
    ll s,t;cin >>s >>t;s--;t--;
    queue<ll> que;
    que.push(s);
    vl dist(3*n,-1);
    dist[s]=0;
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(auto nv:g[v]){
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
            if(nv==t){
                cout << dist[nv]/3 <<endl;
                return 0;
            }
        }
    }
    cout << -1 <<endl;
}