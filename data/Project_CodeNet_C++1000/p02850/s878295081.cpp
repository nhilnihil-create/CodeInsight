#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

vector<vector<P>> g;
VI ans;

void dfs(int v_col, int v, int p){
    int col = 0;
    for(P e: g[v]){
        int d = e.first, i = e.second;
        if (d == p) continue;
        if (ans[i] != -1) continue;
        if (col == v_col) col++;
        ans[i] = col;
        dfs(col, d, v);
        col++;
    }
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    ans.resize(n-1, -1);
    dfs(-1, 0, -1);

    int k = 0;
    rep(i,n-1) chmax(k, ans[i]);
    cout << k + 1 << endl;
    rep(i,n-1){
        cout << ans[i] + 1 << endl;
    }
    return 0;
}