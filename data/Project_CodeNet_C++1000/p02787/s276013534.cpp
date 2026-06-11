#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int INF = 1e9;
// const int MOD = 1e9 + 7;

// 1次元 vector
template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << " ";
        }
        s << vec[i];
    }
    return s << endl;
}
template <class T>  // 2次元 vector
ostream &operator<<(ostream &s, vector<vector<T>> vec2) {
    for (int i = 0; i < (int)vec2.size(); ++i) {
        s << vec2[i];
    }
    return s;
}
int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<int>> dp = make_vec<int>(N + 1, H + 1);
    for (int i = 0; i < N + 1; i++) {
        for (int j = 1; j < H + 1; j++) {
            dp[i][j] = INF;
        }
    }

    for (int n = 0; n < N; n++) {
        for (int h = 0; h <= H; h++) {
            chmin(dp[n][min(h + A[n], H)], dp[n][h] + B[n]);
            chmin(dp[n + 1][h], dp[n][h]);
        }
    }

    cout << dp[N - 1][H] << endl;
}
