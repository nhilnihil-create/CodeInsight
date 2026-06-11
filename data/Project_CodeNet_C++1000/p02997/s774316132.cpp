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

int main() {
    int N, K;
    cin >> N >> K;
    if (K <= (N - 1) * (N - 2) / 2) {
        int add = ((N - 1) * (N - 2) / 2 - K);
        int M = N - 1 + add;
        cout << M << endl;
        for (int i = 1; i < N; i++) {
            cout << 1 << " " << i + 1 << "\n";
        }
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (cnt == add) return 0;
                cout << i + 1 << " " << j + 1 << "\n";
                cnt++;
            }
        }
        return 0;
    }
    cout << -1 << endl;
}
