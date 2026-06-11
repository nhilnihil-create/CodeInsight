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
    string S, T;
    cin >> S >> T;
    int ans = INF;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i + (int)T.size() > (int)S.size()) break;
        int cnt = 0;
        for (int j = 0; j < (int)T.size(); j++) {
            if (S[i + j] != T[j]) cnt++;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
}
