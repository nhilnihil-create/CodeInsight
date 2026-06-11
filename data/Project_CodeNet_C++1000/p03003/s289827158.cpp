#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <cassert>
#include <queue>
#include <unordered_map>
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define rep(i,a,b) for(int i = a;i < b; ++i)
using namespace std;

int add(int a, int b) {
    int MOD = 1e9 + 7;
    a += b;
    if (a < 0) a += MOD;
    return a % MOD;
}
int main() {

    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    vector<int> T(M);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> T[i];
    }
    // f[i][j]:不承诺结尾, 不包括空集
    vector<vector<int>> f(N+1, vector<int>(M+1));
    // dp[i][j]：以S[i-1], T[j-1]为结尾的集合
    vector<vector<int>> dp(N+1, vector<int>(M+1));
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (S[i-1] != T[j-1]) dp[i][j] = 0;
            else dp[i][j] = add(f[i-1][j-1], 1);

            f[i][j] = add(f[i][j], f[i][j-1]);
            f[i][j] = add(f[i][j], f[i-1][j]);
            f[i][j] = add(f[i][j], -f[i-1][j-1]);
            f[i][j] = add(f[i][j], dp[i][j]);
        }
    }
    cout << f[N][M] + 1;

    return 0;
}