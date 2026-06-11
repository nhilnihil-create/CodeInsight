#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

const int MAX_N = 1005;
const int MAX_V = MAX_N*(MAX_N-1)/2;

vector<int> to[MAX_V];
int id[MAX_N][MAX_N];
// 自分と対戦相手の行う試合の頂点番号を返す
int toId(int i, int j){
    if (i > j) swap(i,j);
    return id[i][j];
}
bool visited[MAX_V];
bool calculated[MAX_V];
// vからスタートした時の最長経路を格納
int dp[MAX_V];
int dfs(int v){
    if (visited[v]) {
        // 計算済みではないのに訪問済みの場合は
        // ループが検出されたとして-1とする。
        if (!calculated[v]) return - 1;
        return dp[v];
    }
    visited[v] = true;
    dp[v] = 1;
    for (int u : to[v]){
        int res = dfs(u);
        // ループ検出された場合は-1を返して終了
        if (res == -1) return -1;
        dp[v] = max(dp[v], res+1);
    }
    calculated[v] = true;
    return dp[v];
}

int main(){
    int N; cin >> N;
    // N人がN-1回試合をする。
    // Aに入るのは対戦相手
    vector<vector<int>> A(N,vector<int>(N-1));
    rep(i,N){
        rep(j,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    int v = 0;
    // 1つの試合を一つの頂点とみなす。
    // i,jの組み合わせにすべて頂点番号を付与
    rep(i,N){
        rep(j,N){
            if (i < j){
                id[i][j] = v++;
            }
        }
    }

    rep(i,N){
        rep(j,N-1){
            // A[i][j]を対戦相手から
            // 頂点番号に書き換え
            A[i][j] = toId(i,A[i][j]);
        }
        // 頂点がN-1個あるので、N-2個辺を張る。
        // 逆向きに辺を張る(逆じゃなくともいいらしい)
        rep(j,N-2){
            to[A[i][j+1]].push_back(A[i][j]);
        }
    }
    int ans = 0;
    rep(i,v){
        int res = dfs(i);
        if (res == -1){
            puts("-1");
            return 0;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
} 