#include <stdio.h>
#include <vector>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))

constexpr int mod = 1e9 + 7;
std::vector<int> A, B;
// DP[i][j] := Aを i 文字, Bを j 文字使った時の答え
std::vector<std::vector<int>> DP;

int dfs(int x, int y){
    if(DP[x][y] != -1) return DP[x][y];
    DP[x][y] = dfs(x-1, y) + dfs(x, y-1);
    if(A[x-1] != B[y-1]) DP[x][y] -= dfs(x-1, y-1);
    DP[x][y] %= mod; if(DP[x][y] < 0) DP[x][y] += mod;
    return DP[x][y];
}


int main(void){
    int n, m; scanf("%d%d", &n, &m);
    A.resize(n); REP(i, n) scanf("%d", &A[i]);
    B.resize(m); REP(i, m) scanf("%d", &B[i]);

    DP.resize(n+1, std::vector<int>(m+1, -1));
    FOReq(i, 0, n) DP[i][0] = 1; FOReq(i, 1, m) DP[0][i] = 1;
    int res = dfs(n, m);
    printf("%d\n", res);
    return 0;
}