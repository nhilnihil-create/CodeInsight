#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

template<typename S, typename T, typename U> 
map<S, T> factorization(U p) {
    map<S, T> M;
    U i = 2;
    while (i * i <= p) {
        if (p % i == 0) {
            ++M[i];
            p /= i;
        } else {
            ++i;
        }
    }

    if (p != 1) ++M[p];

    return M;
}

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> M = factorization<int, int, llong>(n);

    vector<int> sum(100);
    sum[0] = 0;
    for (int i = 0; i < 100; ++i) {
        sum[i + 1] = sum[i] + i + 1;
    }

    int ans = 0;
    int resi = 0;
    int cnt = 0;
    stl_rep(itr, M) {
        // cout << itr->first << ' ' << itr->second << endl;
        ans += upper_bound(all(sum), itr->second) - sum.begin() - 1;
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
