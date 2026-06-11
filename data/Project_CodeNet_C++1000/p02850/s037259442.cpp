#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

struct edge{
    int to, id;
};
vector<vector<edge>> G;
vector<int> ans;

void dfs(int v, int color=-1, int parent=-1){

    int k = 1;
    for (edge e : G[v]){
        int to = e.to, id = e.id;
        if (to == parent) continue;
        if (k == color) k++;
        ans[id] = k++;
        dfs(to, ans[id], v);
    }
}

int main(){
    int N; cin >> N;
    ans.assign(N-1,-1);
    G.resize(N);
    rep(i,N-1){
        int a, b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(edge{b,i});
        G[b].push_back(edge{a,i});
    }

    dfs(0);

    int num=0;
    rep(i,N-1) num = max(num, (int)G[i].size());

    cout << num << endl;

    rep(i,N-1){
        cout << ans[i] << endl;
    }
}