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
    int n,m;
    cin>>n>>m;
    Graph G(3*n);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G[3*u].push_back(3*v+1);
        G[3*u+1].push_back(3*v+2);
        G[3*u+2].push_back(3*v);
    }
    int s,t;
    cin>>s>>t;
    s--;t--;
    V<int> dist(3*n,-1);
    queue<int> que;
    dist[3*s]=0;
    que.push(3*s);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int nv:G[v]){
            if(dist[nv]!=-1) continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    int d=dist[3*t];
    if(d==-1||d%3!=0) cout<<-1<<endl;
    else cout<<d/3<<endl;
}
