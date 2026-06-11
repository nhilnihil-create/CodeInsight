
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
#define REP(i, n) FOR(i, 0, n)
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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    int dp1[N + 1][T], dp2[N + 1][T];
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));

    FOR(i, 1, N + 1) {
        FOR(t, 1, T) {
            dp1[i][t] = max(dp1[i - 1][t], dp1[i][t-1]);

            if (t - A[i - 1] > -1) {
                dp1[i][t] = max(dp1[i][t], dp1[i - 1][t - A[i - 1]] + B[i - 1]);
            }
        }
    }

    FOR(i, 1, N + 1) {
        FOR(t, 1, T) {
            dp2[N - i][t] = max(dp2[N - i + 1][t], dp2[N - i][t-1]);

            if (t - A[N - i] > -1) {
                dp2[N - i][t] = max(dp2[N - i][t], dp2[N - i + 1][t - A[N - i]] + B[N - i]);
            }
        }
    }

    int ans = 0;
    REP(i, N) {
        REP(j, T) {
            int tmp = B[i];
            tmp += dp1[i][j];
            tmp += dp2[i + 1][T - j - 1];

            ans = max(ans, tmp);
        }
    }

    print(ans);

}
