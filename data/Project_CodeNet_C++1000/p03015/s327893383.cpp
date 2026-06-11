#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = ll(1e9 + 7);

vector<ll> dp1;
vector<ll> dp2;

ll solve(const string L, const int len) {
    for (int i = 0; i < len; i++) {
        int bit = (L[i + 1] == '1') ? 1 : 0;
        // dp1
        if (bit == 1) {
            dp1[i + 1] = (dp1[i + 1] + 2 * dp1[i]) % MOD;
            dp2[i + 1] = (dp2[i + 1] + dp1[i]) % MOD;
        } else {
            dp1[i + 1] = (dp1[i + 1] + dp1[i]) % MOD;
        }

        // dp2
        dp2[i + 1] = (dp2[i + 1] + 3 * dp2[i]) % MOD;
    }

    return (dp1[len] + dp2[len]) % MOD;
}

int main(void) {
    string L;
    cin >> L;
    int len = (int) L.size();
    L = " " + L;

    dp1.resize(len + 1, 0);
    dp2.resize(len + 1, 0);
    dp1[0] = 1;

    cout << solve(L, len) << endl;

    // cout << "dp1: " << endl;
    // for (int i = 0; i <= len; i++) {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;

    // cout << "dp2: " << endl;
    // for (int i = 0; i <= len; i++) {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;

    return 0;
}
