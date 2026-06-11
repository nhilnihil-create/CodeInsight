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
    ll n,k;cin >> n >>k;
    vvl g(n);
    rep(i,n-1){
        ll a,b;cin >>a >>b;a--;b--;
        g[a].pb(b);g[b].pb(a);
    }
    queue<ll> que;
    que.push(0);
    vl seen(n,0);
    seen[0]=1;
    ll ans=k;
    while(!que.empty()){
        ll v=que.front();que.pop();
        ll cnt=0;
        seen[v]=1;
        for(auto nv:g[v]){
            if(seen[nv])continue;
            if(v==0){
                ans*=k-cnt-1;
                if(k-cnt-1==0){
                    cout <<0 <<endl;
                    return 0;
                }
            }
            else{
                ans*=k-cnt-2;
                if(k-cnt-2==0){
                    cout <<0 <<endl;
                    return 0;
                }
            }
            ans%=MOD;
            cnt++;
            que.push(nv);
        }
    }
    cout <<ans <<endl;
}