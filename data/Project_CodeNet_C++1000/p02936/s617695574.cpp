#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define Dcout(a) cout << setprecision(20) << a << endl
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define fi first
#define se second
using Graph = vector<vector<int>>;
const ll INF = (1LL << 60);
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/
Graph G;
vector<int> ans;
void dfs(int v, int p=-1){
    //頂点vを根とする部分木にans[v]を加算する
    for(int nv: G[v]){
        if(nv==p) continue;
        ans[nv] += ans[v];
        //加算後にその頂点に対して再びdfs
        dfs(nv,v);
    }
}
/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    //n頂点とクエリの数qを入力
    int n, q; cin >> n >> q;
    G.resize(n);

    //辺を入力
    rep(i, n-1){
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans.resize(n);

    //クエリを入力
    rep(i,q){
        int p, x; cin >> p >> x;
        --p;
        ans[p] += x;
    }

    //根から順にdfsする
    dfs(0);

    rep(i,n) cout << ans[i] << endl;

}
/********  Main() Ends Here *************/
