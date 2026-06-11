#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

ll dp[2010][2010];
ll sum[2010][2010];

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    // dp[i][j]:=Sが[0,i)、Tが[0,j)まで見て、最後にS[i-1]==T[j-1]をとる場合の数
    dp[0][0] = 1;
    sum[1][1] = 1;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0 && j == 0)
                continue;
            if(i != 0 && j != 0 && S[i - 1] == T[j - 1]) {
                dp[i][j] = sum[i][j];
            }
            sum[i + 1][j + 1] =
                (sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + dp[i][j] + MOD) %
                MOD;
        }
    }

    cout << sum[N + 1][M + 1] << endl;
    return 0;
}