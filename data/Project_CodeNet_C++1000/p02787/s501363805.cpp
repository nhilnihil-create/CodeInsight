#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
// dp[i+1][j]:i番目までの魔法で体力をj以上減らすための魔力の最小値
int main()
{
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(H + 1, INF_64));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][min(j + A[i], H)], dp[i + 1][j] + B[i]);
        }
    }
    cout << dp[N][H] << endl;
    return 0;
}