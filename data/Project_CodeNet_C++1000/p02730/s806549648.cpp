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

    const ll N = S.size(); for (int i = 0; i < N / 2; ++i) {
        if (S[i] != S[N - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < (N - 1) / 2 - 1; ++i) {
        if (S[i] != S[(N - 1) / 2 - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = (N + 3) / 2 - 1; i < N; ++i) {
        if (S[i] != S[N - 1 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}