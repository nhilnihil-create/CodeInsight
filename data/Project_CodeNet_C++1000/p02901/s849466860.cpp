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

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}
int dp[(1 << 12) + 1][1010];
// vector<vector<int>> dp(1 << 12 + 1, vector<int>(1010, INF_32));
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> c(M, 0);
    for (int i = 0; i < M; i++) {
        int b;
        cin >> a[i] >> b;
        for (int j = 0; j < b; j++) {
            int inp;
            cin >> inp;
            inp--;
            c[i] |= (1 << inp);
        }
    }

    Fill(dp, INF_32);
    dp[0][0] = 0;
    for (int i = 0; i < M; i++) {
        for (int bit = 0; bit <= (1 << N) - 1; bit++) {
            dp[bit | c[i]][i + 1] = min(dp[bit | c[i]][i + 1], dp[bit][i] + a[i]);
            dp[bit][i + 1] = min(dp[bit][i + 1], dp[bit][i]);
        }
    }

    cout << ((dp[(1 << N) - 1][M] == INF_32) ? -1 : dp[(1 << N) - 1][M]) << endl;
    return 0;
}