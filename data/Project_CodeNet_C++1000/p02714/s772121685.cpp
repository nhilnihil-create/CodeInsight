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
    int N;
    cin >> N;
    string S;
    cin >> S;

    set<int> mR, mG, mB;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            mR.emplace(i);
        } else if (S[i] == 'G') {
            mG.emplace(i);
        } else {
            mB.emplace(i);
        }
    }

    ll ans = mR.size() * mG.size() * mB.size();
    for (auto R : mR) {
        for (auto G : mG) {
            if ((R + G) % 2 == 0) {
                if (mB.find((R + G) / 2) != mB.end()) {
                    --ans;
                }
            }

            if (mB.find(2 * G - R) != mB.end()) {
                --ans;
            }
            if (mB.find(2 * R - G) != mB.end()) {
                --ans;
            }
        }
    }
    cout << ans << endl;
}