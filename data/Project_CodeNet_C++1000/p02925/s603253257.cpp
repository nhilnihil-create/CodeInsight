#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
// const int mod=998244353;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

vector<bool> visited,passed;
vi d;

int dfs(vvi &g,int v){
    if(visited[v])return passed[v]?d[v]:-1;
    visited[v]=true;
    for(int u:g[v]){
        int t=dfs(g,u);
        if(t==-1)return -1;
        d[v]=max(d[v],t+1);
    }
    passed[v]=true;
    return d[v];
}

void run(){
    int n;
    cin>>n;
    vvi a(n,vi(n-1));
    rep(i,n)rep(j,n-1)cin>>a[i][j],a[i][j]--;
    int N=n*(n-1)/2;
    vvi b(n,vi(n));
    int id=0;
    rep(i,n)Rep(j,i+1,n)b[i][j]=b[j][i]=id++;
    vvi g(N);
    rep(i,n)rep(j,n-2)g[b[i][a[i][j]]].eb(b[i][a[i][j+1]]);
    visited=vector<bool>(N);
    passed=vector<bool>(N);
    d=vi(N,1);
    int ans=0;
    rep(i,id){
        int t=dfs(g,i);
        if(t==-1){
            cout<<-1<<endl;
            return;
        }
        ans=max(ans,t);
    }
    cout<<ans<<endl;
}