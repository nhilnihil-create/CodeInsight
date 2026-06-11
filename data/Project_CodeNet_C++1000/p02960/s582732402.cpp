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

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;

        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


const int MOD = 1e9 + 7;
vector<vl> dp;

void f(int i, int curr) {
    for (int j = 0; j < 13; j++) {
        // 遷移先
        int x = (j + curr) % 13;

        dp[i][x] += dp[i - 1][j];
        dp[i][x] %= MOD;
    }
}

int main() {
    string S; cin >> S;
    // NOTE: reverseしたら0の扱いが面倒そう (途中に0が出てくるやつ)
    int N = S.size();

    dp.resize(N + 1, vl(13, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        ll digit = modpow(10, N - i, 13);

        if (S.at(i - 1) == '?') {
            for (int j = 0; j < 10; j++) {
                int curr = (j * digit) % 13;
                f(i, curr);
            }
        } else {
            int curr = ((S.at(i - 1) - '0') * digit) % 13;
            f(i, curr);
        }
    }

    // rep(i, N + 1) {
    //     rep(j, 13) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][5] << endl;
}
