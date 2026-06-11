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

#define INF 1e9

int n;
vi opp;
vector<bool> seen;
vi weight;

int dfs(int v){
    if (weight[v]!=-1) return weight[v];
    if (seen[v] && weight[v]==-1) return INF;
    int u = opp[v];
    seen[v]=seen[u]=true;
    int wv,wu;
    wv = (v%(n-1)==0) ? 1 : dfs(v-1)+1 ;
    wu = (u%(n-1)==0) ? 1 : dfs(u-1)+1 ;
    // if (v%(n-1)==0) wv=1; else wv=dfs(v-1)+1;
    // if (u%(n-1)==0) wu=1; else wu=dfs(u-1)+1;
    weight[v]=weight[u]=max(wv,wu);
    return weight[v];
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int N = n*(n-1);
    vector<vi> a(n, vi(n-1));
    vector<vi> rev(n, vi(n));
    rep(i,n)rep(j,n-1){
        cin>>a[i][j]; a[i][j]--;
        rev[i][a[i][j]] = j;
    }
    opp.resize(N);
    rep(i,n)rep(j,n-1){
        int id = (n-1)*i+j;
        opp[id] = (n-1)*a[i][j]+rev[a[i][j]][i];
    }
    weight.resize(N,-1);
    seen.resize(N,false);
    int ans=0;
    rep(i,N) chmax(ans,dfs(i));
    cout<<((INF>ans)?ans:-1)<<"\n";
    return 0;
}
