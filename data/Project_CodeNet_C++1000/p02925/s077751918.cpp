#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const int MAX_N = 1005;
const int MAX_V = MAX_N*(MAX_N-1)/2;
vector<int> to[MAX_V];
int id[MAX_N][MAX_N];
int n;
int toId(int i, int j) {
    if(i > j) swap(i, j);
    return id[i][j];
}

bool visited[MAX_V];
bool calculated[MAX_V];
int dp[MAX_V];  // from vの最長経路を保存する
int dfs(int v) {
    if(visited[v]) {
        if(!calculated[v]) return -1;
        return dp[v];
    }
    visited[v] = true;
    dp[v] = 0;
    for(int u : to[v]) {
        int res = dfs(u);
        if(res == -1) return -1;
        dp[v] = max(dp[v], dfs(u)+1);
    }
    calculated[v] = true;
    return dp[v];
}


int main() {
    cin >> n;
    vector< vector<int> > Amap(n, vector<int>(n-1));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n-1; ++j) {
            cin >> Amap[i][j];
            Amap[i][j]--;
        }
    }
    int V = 0;  // 頂点番号
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i < j) {
                // 試合のセットを頂点としていく
                id[i][j] = V++;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        // 入力のAmapの数字を頂点番号へ書き換える
        for(int j = 0; j < n-1; ++j) {
            Amap[i][j] = toId(i, Amap[i][j]);
        }
        // 右に行くほど大きくなるように有向辺を張る
        for(int j = 0; j < n-2; ++j) {
            to[Amap[i][j+1]].push_back(Amap[i][j]);
        }
    }

    // トポロジカルソートしてる
    int ans = 0;
    for(int i = 0; i < V; ++i) {
        int res = dfs(i);
        if(res == -1) {
            // ループがある時点でどんなルートでもループにはまるのでエラー
            cout << -1 << endl;
            return 0;
        }
        chmax(ans, res+1);
    }
    cout << ans << endl;
}