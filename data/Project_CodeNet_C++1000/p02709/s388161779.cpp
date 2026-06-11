
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


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;

    vector<pair<ll, int>> A(N);
    REP(i, N) {
        ll a;
        cin >> a;
        A[i] = {a, i};
    }

    sort(ALL(A));
    reverse(ALL(A));

    ll dp[N + 2][N + 2];
    memset(dp, 0, sizeof(dp));

    REP(i, N) {
        REP(y, i + 2) {
            int x = i - y + 1;
            if (x > 0) dp[x][y] = max(dp[x][y], dp[x - 1][y] + A[i].fi * (A[i].se - x + 1));
            if (y > 0) dp[x][y] = max(dp[x][y], dp[x][y - 1] + A[i].fi * (N - y - A[i].se));
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans = max(ans, dp[N - i][i]);
    }
    print(ans);
}
