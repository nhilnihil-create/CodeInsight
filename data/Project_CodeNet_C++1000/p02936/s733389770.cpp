#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
using Graf_l=vector<list<int>>;

Graf g(200010);
vector<ll> x(200010,0);
vector<bool> vis(200010,false);

void dfs(int p,ll y){
    if(vis[p]==true){
        return;
    }
    vis[p]=true;
    x[p]+=y;
    if(g[p].empty()){
        return;
    }
    rep(i,g[p].size()){
        dfs(g[p][i],x[p]);
    }
    return;
}

int main()
{
    int n,q;
    cin >> n >> q;
    
    int a,b;
    ll p,val;
    rep(i,n-1){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    rep(i,q){
        cin >> p >> val;
        x[p-1]+=val;
    }
    dfs(0,0);
    rep(i,n){
        cout << x[i] << " ";
    }
    cout << endl;
}