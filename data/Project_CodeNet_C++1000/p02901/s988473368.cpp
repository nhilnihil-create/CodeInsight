
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
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = ((n) - 1); i >= (m); --i)
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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N, M;
    cin >> N >> M;

    vll A(M), C(M, 0);

    REP(i, M) {
        int b; cin >> A[i] >> b;
        REP(j, b) {
            int c;
            cin >> c;
            --c;
            C[i] |= (1LL << c);
        }
    }

    ll SMAX = (1 << N) + 5;
    ll dp[M + 1][SMAX];
    REP(i, M + 1) REP(j, SMAX) dp[i][j] = INF;
    dp[0][0] = 0;

    REP(i, M) {
        REP(j, 1 << N) {
            REP(k, N) {
                if (!(C[i] >> k & 1) || j >> k & 1) continue;

                // i-1 -> i
                dp[i + 1][j | 1 << k] = min(dp[i + 1][j | 1 << k], dp[i][j] + A[i]);

                // i -> i
                dp[i + 1][j | 1 << k] = min(dp[i + 1][j | 1 << k], dp[i + 1][j]);

            }

            dp[i + 1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }

    print(dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1]);
}
