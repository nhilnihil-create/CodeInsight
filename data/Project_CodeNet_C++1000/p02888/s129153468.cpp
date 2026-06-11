#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

int binary_search(int first, int a, int b, vi &l) {
    int ng = first - 1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = N;         // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        bool isOK = false;
        int c = l[mid];
        if (c < a + b) {
            isOK = true;
        }
        if (isOK)
            ok = mid;
        else
            ng = mid;
    }
    dump(ok, a, b, l[ok]);
    return ok;
}

signed main() {
    cin >> N;
    vi l(N);
    cin >> l;
    sort(ALL(l));
    REP(i, N)
    FOR(j, i + 1, N) {
        int tmp = upper_bound(l.begin() + j + 1, l.end(), l[i] + l[j] - 1) - l.begin() - j - 1;
        dump(i, j, tmp + j + 1);
        ans += tmp;
    }
    cout << ans << endl;
}