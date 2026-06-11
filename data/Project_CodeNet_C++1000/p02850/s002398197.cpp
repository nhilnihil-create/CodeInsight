#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int id;
    edge(int t, int w) : to(t),id(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<edge>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

Graph G;
vector<int> ans;
int ans_ko;
void dfs(int v,int c = -1, int p = -1){
    chmax(ans_ko,c);
    int k = 1;
    for(auto n : G[v]){
        int nv = n.to; int ei = n.id;
        if(nv == p) continue;
        if(k == c) ++k;
        ans[ei] = k;
        ++k;
        dfs(nv,ans[ei],v);
    }
}

int main(){

    int n; cin >> n;
    G.resize(n);
    ans.resize(n-1);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        --a;--b;
        G[a].push_back(edge(b,i));
        G[b].push_back(edge(a,i));
    }
    ans_ko = 0;
    dfs(0);
    cout << ans_ko << endl;
    rep(i,n-1) cout << ans[i] << endl;

}