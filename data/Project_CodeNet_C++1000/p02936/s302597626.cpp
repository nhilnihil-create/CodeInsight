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

const int N_MAX = 2e5;

vi G[N_MAX];
int ans[N_MAX];

void dfs(int v, int p=-1)
{
    for(auto u:G[v]){
        if (u==p) continue;
        ans[u]+=ans[v];
        dfs(u,v);
    }
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin>>N>>Q;
    rep(i,N-1){
        int a,b; cin>>a>>b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    while(Q--){
        int p,x; cin>>p>>x; p--;
        ans[p]+=x;
    }
    dfs(0);
    rep(i,N){
        if (i>0) cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}
