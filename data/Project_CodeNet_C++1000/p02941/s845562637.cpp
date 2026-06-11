#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define int ll
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
    vi a(N), b(N);
    cin >> a >> b;
    bool flag = 1;
    while (1) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < N; i++) {
            dump(a, b);
            if (a[i] == b[i]) {
                cnt1++;
                continue;
            }
            int tmp;
            if (i == 0) {
                tmp = b[N - 1] + b[1];
            } else if (i == N - 1) {
                tmp = b[N - 2] + b[0];
            } else {
                tmp = b[i - 1] + b[i + 1];
            }
            if (b[i] < tmp) {
                cnt2++;
            } else {
                if (a[i] >= b[i] % tmp) {
                    if ((b[i] - a[i]) % tmp == 0) {
                        ans += (b[i] - a[i]) / tmp;
                        b[i] = a[i];
                    } else {
                        flag = 0;
                        break;
                    }
                } else {
                    ans += b[i] / tmp;
                    b[i] %= tmp;
                }
            }
        }
        if (cnt2 == N) {
            flag = 0;
        }
        if (cnt1 == N || flag == 0) {
            break;
        }
    }

    if (flag) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}