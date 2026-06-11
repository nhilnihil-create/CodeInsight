#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 303;
const int inf = (int)1e15;

int n, k, h[N], f[N][N];

int Cost(int i, int j) {
    if(h[i] >= h[j]) return 0;
    return h[j] - h[i];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    fill_n(&f[0][0], N * N, inf);
    ++n; f[1][0] = h[1]; f[0][0] = 0;
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            f[i][j] = f[i - 1][j] + Cost(i - 1, i);
            for(int t = i - 2; t >= 0; --t) {
                if(i - t - 1 > j) break;
                f[i][j] = min(f[i][j], f[t][j - i + t + 1] + Cost(t, i));
            }
        }
    }
    int res = inf;
    for(int i = 0; i <= k; ++i) res = min(res, f[n][i]);
    cout << res;
}
