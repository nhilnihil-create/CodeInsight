#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair<int,int> P;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define rep(i,a,n) for(int i=a;i<n;i++)


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

#define Nmax 200005

vector<vector<int>>G;
llint f[Nmax];
int n,q;


void dfs(int v,int p=-1){
    for(int u:G[v]){
        if(u==p)continue;
        f[u]+=f[v];
        dfs(u,v);
    }
}


void solve(){
    cin >> n >> q;
    G.resize(n+1);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,0,q){
        int p,x;
        cin >> p >> x;
        p--;
        f[p]+=x;
    }
    dfs(0);
    rep(i,0,n)cout << f[i] << " ";
    cout << endl;
}

int main(){
    solve();
    return 0;
}



