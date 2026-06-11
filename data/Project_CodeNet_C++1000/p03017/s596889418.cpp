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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--, B--, C--, D--;
    string S;
    cin >> S;

    for (int i = B; i < D; i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            cout << "No\n";
            return 0;
        }
    }
    for (int i = A; i < C; i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            cout << "No\n";
            return 0;
        }
    }

    bool flag = true;
    if (C > D) {  // 追い越す必要があるとき
        flag = false;
        for (int i = B; i <= D; i++) {
            if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
