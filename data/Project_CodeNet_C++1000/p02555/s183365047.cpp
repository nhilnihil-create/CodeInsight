#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

const ll MOD = 1e9 + 7;

int main() {
    int S; cin >> S;

    vl dp(S + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= S; i++) {
        for (int j = i - 3; j >= 0; j--) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[S] << endl;
}
