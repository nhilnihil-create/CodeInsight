#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

vector<ll> G[200050];//辺
vector<ll> stock(200050,0);
vector<bool> visited(200050);

void dfs(ll x){
    visited[x]=true;
    
    rep(i,sz(G[x])){
        if(!visited[G[x][i]]){
            stock[G[x][i]]+=stock[x];
            dfs(G[x][i]);
        }
    }
}

int main(){
    ll N,Q; cin>>N>>Q;
    rep(i,N-1){
        ll A,B; cin>>A>>B;
        G[A].pb(B);
        G[B].pb(A);
    }
    rep(i,Q){
        ll p,x; cin>>p>>x;
        stock[p]+=x;
    }
    dfs(1);
    rep1(i,N){
        cout<<stock[i]<<" ";
    }
}

