#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define BUF 1e5
#define INF 1 << 30
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) (a).begin(), (a).end()
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
constexpr ll mod = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = (i ^ j);
            int tmp = 0;
            dump(x, x & 1);
            while (!(x & 1)) {
                x /= 2;
                tmp++;
            }
            cout << tmp + 1 << endl;
        }
    }
}