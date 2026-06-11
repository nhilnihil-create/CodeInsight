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
#define INF (1 << 30 - 1)
#define LLINF (1LL << 60)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
ll V, T;
string S;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N >> K;
    vector<int> a(N), b(N + 1);
    cin >> a;
    int cnt = 0;
    int k = 0;
    while (cnt != N && k < K) {
        cnt = 0;
        k++;
        REP(i, N) {
            int l = max(i - a[i], 0);
            int r = min(i + a[i] + 1, int(N));
            b[l]++;
            b[r]--;
        }
        REP(i, N) {
            b[i + 1] += b[i];
        }
        REP(i, N) {
            a[i] = b[i];
        }
        fill(ALL(b), 0);
        cnt = count(ALL(a), N);
    }
    REP(i, N) {
        cout << a[i] << " ";
    }
}
