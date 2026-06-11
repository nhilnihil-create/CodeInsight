#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

vector<vll> dp;
vll A, C;

void init(ll N, ll M) {
    dp = vector<vll>(M + 1, vll(1 << N, -1));
    dp[0][0] = 0;
    ll i;
    for(i = 1; i < 1 << N; i++) {
        dp[0][i] = INF;
    }
}

ll sub(ll m, ll S) {
    if(dp[m][S] != -1) {
        return dp[m][S];
    }
    dp[m][S] = min(sub(m - 1, S), sub(m - 1, S & ~C[m - 1]) + A[m - 1]);
    return dp[m][S];
}

int main() {
    ll i, j, k;
    ll N, M;
    cin >> N >> M;
    init(N, M);
    for(i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        ll ci = 0;
        for(j = 0; j < b; j++) {
            ll c;
            cin >> c;
            c--;
            ci = ci | 1 << c;
        }
        C.push_back(ci);
    }
    ll ans = sub(M, (1 << N) - 1);
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
