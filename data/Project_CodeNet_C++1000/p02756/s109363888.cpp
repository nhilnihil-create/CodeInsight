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
    string S;
    cin >> S;
    ll Q;
    cin >> Q;

    string add1;
    string add2;
    bool omote = true;
    for (int i = 0; i < Q; ++i) {
        ll T;
        cin >> T;
        if (T == 1) {
            omote = !omote;
        } else {
            ll F;
            string C;
            cin >> F >> C;
            if (F == 1) {
                if (omote) {
                    add1 += C;
                } else {
                    add2 += C;
                }
            } else {
                if (omote) {
                    add2 += C;
                } else {
                    add1 += C;
                }
            }
        }
    }

    reverse(all(add1));
    if (omote) {
        cout << add1 << S << add2 << endl;
    } else {
        reverse(all(add1));
        reverse(all(add2));
        reverse(all(S));
        cout << add2 << S << add1 << endl;
    }
}