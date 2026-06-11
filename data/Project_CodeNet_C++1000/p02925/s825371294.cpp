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
    ll n;cin >> n;
    vector<queue<ll>> v(n);
    rep(i,n){
        rep(j,n-1){
            ll x;cin >> x;x--;
            v[i].push(x);
        }
    }
    ll day=0,end=0;
    set<ll> prematch;
    rep(i,n)prematch.ins(i);
    while(true){
        ll preend=end;
        set<ll> match;
        vector<bool> check(n,false);
        for(auto i:prematch){
            if(v[i].empty())continue;
            if(check[i])continue;
            ll x=v[i].front();
            if(v[x].empty())continue;
            if(check[x])continue;
            if(v[x].front()==i){
                v[i].pop();v[x].pop();
                check[i]=true;check[x]=true;
                end+=2;
                match.ins(i);match.ins(x);
            } 
        }
        day++;
        if(preend==end){
            cout << -1 <<endl;
            return 0;
        }
        if(end==n*(n-1))break;
        prematch=match;
    }
    cout << day <<endl;
}