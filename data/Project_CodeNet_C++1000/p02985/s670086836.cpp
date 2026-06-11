#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1e18;

signed main(){
    ll n,k;
    cin>>n>>k;
    Graph G(n);
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    ll ans=k;
    V<ll> dist(n,-1);
    queue<ll> que;
    V<set<ll>> st(n);
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        ll v=que.front();
        que.pop();
        for(ll nv:G[v]){
            st[nv].insert(v);
            st[v].insert(nv);
            if(dist[nv]!=-1) continue;
            ll m=st[v].size();
            if(k-m<0) ans=0;
            else ans=(ans*(k-m))%mod;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    cout<<ans<<endl;
}