#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

ll N, M, K, Q;
string S;

int main() {
    cin >> N;
    cin >> S;
    vector<int> a(N);
    vector<int> cnt(3);
    for (int i = 0; i < N; i++) {
        a[i] = (int)(S[i] - '1');
        cnt[a[i]]++;
    }

    if (cnt[1] > 0) {
        bool is_odd = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == 1) {
                is_odd ^= (((N - 1) & i) == i);
            }
        }
        if (is_odd) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        bool is_odd = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == 2) {
                is_odd ^= (((N - 1) & i) == i);
            }
        }
        if (is_odd) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
