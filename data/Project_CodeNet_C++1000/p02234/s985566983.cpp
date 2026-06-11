#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;
//
//ll matrix_chain_multiplications(vector<int>& p) {
//    int n = p.size() - 1; // num of matrix
//    vector<vll> dp(n + 1, vll(n + 1, INF));
//
//    // init
//    FOR(i, 1, n + 1) dp[i][i] = 0;
//
//    FOR(l, 2, n + 1) {
//        FOR(i, 1, n - l + 2) {
//            int j = i + l - 1;
//            FOR(k, i, j) {
//                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i - 1] * p[k] * p[j]);
//            }
//        }
//    }
//
//    return dp[1][n];
//}

// 0-indexed
ll matrix_chain_multiplications(vector<int>& p) {
    int n = p.size() - 1; // num of matrix
    vector<vll> dp(n, vll(n, INF)); // dp[l][r] = minimum cost of [l, r], 0 <= l, r < n

    // init
    FOR(i, 0, n) dp[i][i] = 0;

    FOR(l, 2, n + 1) { // l = 2 ~ n
        REP(i, n - l + 1) {
            int j = i + l - 1;
            FOR(k, i, j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i] * p[k + 1] * p[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n; cin >> n;

    vi p(n + 1);
    REP(i, n) cin >> p[i] >> p[i + 1];

    print(matrix_chain_multiplications(p));
}
