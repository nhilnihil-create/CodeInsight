#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

vector<vi> adj;
vector<bool> seen;
vector<bool> finished;
vi topo;

bool dfs(int v)
{
    bool ret=true;
    seen[v]=true;
    for(auto u:adj[v]){
        if (finished[u]) continue;
        if (seen[u] && !finished[u]) return false;
        if (!dfs(u)) ret=false;
    }
    finished[v]=true;
    topo.pb(v);
    return ret;
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<vi> a(n,vi(n-1));
    vector<vi> rev(n,vi(n));
    rep(i,n)rep(j,n-1){
        cin>>a[i][j]; a[i][j]--;
        rev[i][a[i][j]] = j;
    }
    int N=0;
    vector<vi> p(n,vi(n-1,-1));
    rep(i,n)rep(j,n-1){
        if (p[i][j]!=-1) continue;
        int oi = a[i][j];
        int oj = rev[oi][i];
        p[i][j] = N;
        p[oi][oj] = N++;
    }
    adj.resize(N);
    seen.resize(N);
    finished.resize(N);
    rep(i,n)rep(j,n-2){
        adj[p[i][j]].pb(p[i][j+1]);
    }
    rep(i,N)if(!seen[i] && !dfs(i)){
        cout<<"-1\n";
        return 0;
    }
    reverse(all(topo));
    vi dist(N);
    int ans=0;
    rep(i,N){
        int v = topo[i];
        for(auto u:adj[v]){
            chmax(dist[u],dist[v]+1);
        }
        chmax(ans,dist[v]);
    }
    cout<<ans+1<<"\n";
    return 0;
}
