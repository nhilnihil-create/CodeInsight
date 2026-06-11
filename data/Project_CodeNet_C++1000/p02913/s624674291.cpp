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

vector<int> z_algorithm(const string &s) {
    vector<int> prefix(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while (i + k < s.size() && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (int)s.size();
    return prefix;
}

signed main() {
    cin >> N >> S;
    REP(i, N) {
        T = S.substr(i);
        auto v = z_algorithm(T);
        REP(i, T.size()) {
            if (i == 0)
                continue;
            ans = max(min(v[i], i), (int)ans);
        }
    }
    cout << ans << endl;
}