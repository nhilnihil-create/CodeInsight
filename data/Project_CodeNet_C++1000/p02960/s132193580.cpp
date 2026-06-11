#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    ll ten = 1;
    vector<ll> cnt(13);
    cnt.at(0) = 1;
    for (char c : s) {
        vector<ll> tmp(13);
        if (c == '?') {
            for (int i=0; i<10; ++i) {
                int shift = ten * (ll)i % 13;
                for (int j=0; j<13; ++j) tmp.at((j+shift)%13) += cnt.at(j);
                for (int j=0; j<13; ++j) tmp.at(j) %= MOD;
            }
        } else {
            int shift = ten * (ll)(c-'0') % 13;
            for (int i=0; i<13; ++i) tmp.at((i+shift)%13) += cnt.at(i);
            for (int i=0; i<13; ++i) tmp.at(i) %= MOD;
        }
        cnt = tmp;
        ten *= 10;
        ten %= 13;
    }
    cout << cnt.at(5) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
