#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<ll>> G(N, vector<ll>(D));
    rep(i, N) {
        rep(j, D) { cin >> G[i][j]; }
    }

    ll ans = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; j++) {
            if (i == j)
                continue;
            ll tmp = 0;
            rep(k, D) { tmp += (G[i][k] - G[j][k]) * (G[i][k] - G[j][k]); }
            for (int l = 0; l * l <= tmp; l++) {
                if (l * l == tmp)
                    ans++;
            }
        }
    }

    cout << ans << endl;
}