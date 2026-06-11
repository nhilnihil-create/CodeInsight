#include <iostream>
#include <map>
#include <vector>
using namespace std;
constexpr int N_max = 2'000;
constexpr int M_max = 2'000;
constexpr int mod = 1'000'000'007;

#ifdef _MSC_VER
constexpr int debug = 1;
#else
constexpr int debug = 0;
#endif

//             s-pos  t-pos
static int dp0[2'005][2'005];
static int dp1[2'005][2'005];

int main() {
    int n, m;
    cin >> n >> m;
    auto s = vector<int>(n + 5);
    auto t = vector<int>(m + 5);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < m; j++)
        cin >> t[j];

    dp0[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp0[i + 1][j] = (dp0[i + 1][j] + dp0[i][j]) % mod;
            dp1[i][j] = (dp1[i][j] + dp0[i][j]) % mod;
            dp1[i][j + 1] = (dp1[i][j + 1] + dp1[i][j]) % mod;
            if (s[i] == t[j]) {
                dp0[i + 1][j + 1] = (dp0[i + 1][j + 1] + dp1[i][j]) % mod;
            }
        }
    }

    cout << dp1[n][m];
    return 0;
}
