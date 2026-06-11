#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

vll ans;
vector<bool> seen;
void dfs(const vector<vll> &G, ll v){
    seen[v] = true;
    for(auto g:G[v]){
        if(seen[g])continue;
        ans[g] += ans[v];
        dfs(G,g);
    }
}

int main()
{
    int N,Q;
    cin >> N >> Q;
    vector<vll> G(N);
    ans.assign(N,0);
    seen.assign(N,false);
    REP(i,N-1){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    REP(i,Q){
        ll a,b;
        cin >> a >> b;
        a--;
        ans[a]+=b;
    }
    REP(i,N){
        if(seen[i])continue;
        dfs(G,i);
    }
    REP(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
}