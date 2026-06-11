#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    string N;
    cin >> N;
    map<char, string> ans = {
        {'0', "pon"}, {'1', "pon"}, {'2', "hon"}, {'3', "bon"}, {'4', "hon"},
        {'5', "hon"}, {'6', "pon"}, {'7', "hon"}, {'8', "pon"}, {'9', "hon"},
    };
    cout << ans[N[N.size() - 1]] << endl;
}