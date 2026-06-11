#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

#define INF 1<<30

int main() {
    int N, M; cin >> N >> M;
    vector<int> a(M), b(M), c(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            int tmp; cin >> tmp;
            tmp--;
            c[i] += (1<<tmp);
        }
    }
    vector<vector<int>> dp(M+1, vector<int>(1<<N, INF));
    dp[0][0] = 0;
    rep(i, M) {
        rep(j, 1<<N) {
            chmin(dp[i+1][j], dp[i][j]); // 取らない
            int nj = (j|c[i]);
            chmin(dp[i+1][nj], dp[i][j] + a[i]); //　取る
        }
    }
    cout << (dp[M][(1<<N)-1] < INF ? dp[M][(1<<N)-1] : -1) << endl;
}