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
ll n;
vpl v;
ll memo[2010][2010];
ll dfs(ll l,ll r){
    if(l>r)return 0;
    if(memo[l][r]!=-1)return memo[l][r];
    ll now=n-(r+1-l);
    ll ret1=v[now].fi*abs(v[now].se-l);
    ll ret2=v[now].fi*abs(v[now].se-r);
    ll ret=max(ret1+dfs(l+1,r),ret2+dfs(l,r-1));
    memo[l][r]=ret;
    return ret;
}
int main(){
    cin >> n;
    v.resize(n);
    rep(i,n){
        ll a;cin >> a;
        v[i]={a,i};
    }
    sort(all(v));rev(all(v));
    rep(i,2010)rep(j,2010)memo[i][j]=-1;
    cout << dfs(0,n-1) <<endl;
} 