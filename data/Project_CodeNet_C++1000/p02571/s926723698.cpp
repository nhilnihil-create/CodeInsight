#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P   = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()

void solve(std::string S, std::string T) {
    i64 ans = T.length();
    rep(i, S.length() - T.length() + 1) {
        i64 cost = 0;
        rep(j, T.length()) {
            if(S[i + j] != T[j]) ++cost;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main() {
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(S, T);
    return 0;
}
