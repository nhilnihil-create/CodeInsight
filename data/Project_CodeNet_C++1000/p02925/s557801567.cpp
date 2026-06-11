#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int maxN = 1005;
const int maxV = maxN * (maxN - 1) / 2;
vector<int> to[maxV];
int id[maxN][maxN];
int vtoId(int x, int y) {
    if (y < x) swap(x, y);
    return id[x][y];
}

bool visited[maxV];
bool calted[maxV];
int dp[maxV]; // max length
int dfs(int x) {
    if (visited[x]) {
        if (!calted[x]) return -1;
        else return dp[x];
    }
    dp[x] = 1;
    visited[x] = true;
    for (int a : to[x]) {
        int y = dfs(a);
        if (y == -1) return -1;
        dp[x] = max(dp[x], y + 1);
    }
    calted[x] = true;
    return dp[x];
}

int main() {
    // DAG, 閉路検出、最長パス
    int N;
    cin >> N;
    int V = 0;
    rep(j, N) rep(i, j) {
        id[i][j] = V++;
    }
    vector<vector<int>> A(N, vector<int> (N-1));
    rep(i, N) {
        rep(j, N-1) {
            cin >> A[i][j];
            --A[i][j];
            A[i][j] = vtoId(i, A[i][j]);
        }
        rep(j, N-2) {
            to[A[i][j+1]].push_back(A[i][j]);
        }
    }
    int ans = 0;
    rep(i, V) {
        int x = dfs(i);
        if (x == -1) {
            cout << -1 << '\n';
            return 0;
        }
        ans = max(ans, x);
    }
    cout << ans << '\n';
    return 0;
}

// 36