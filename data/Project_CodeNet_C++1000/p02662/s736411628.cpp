#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

const int MAX_S = 3000;
const int MOD = 998244353;

vector<int> as;

vector<int> dp;

int main(void) {
    int N, S;
    cin >> N >> S;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    dp.resize(MAX_S + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        const int a = as[i];
        for (int j = MAX_S; j >= 0; j--) {
            if (j + a <= MAX_S) {
                // use a
                dp[j + a] = (dp[j + a] + dp[j]) % MOD;
            }
            // not use a
            dp[j] = (dp[j] * 2) % MOD;
        }
    }

    // for (int i = 0; i <= S; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[S] << endl;

    return 0;
}
