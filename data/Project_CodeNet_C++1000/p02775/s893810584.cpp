#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    string N;
    while (N.size() <= 1e6-S.size()) {
        N += '0';
    }

    N += S;

    // cout << N.size() << "\n";

    mat dp(1e6+2, vec(2, inf));
    dp[0][0] = 0;
    // dp[i][larger]
    Rep (i, 1e6+1) {
        // larger 0 to 0
        chmin(dp[i+1][0], dp[i][0] + N[i] - '0');

        // larger 0 to 1
        if (N[i] - '0' < 9) {
            chmin(dp[i+1][1], dp[i][0] + N[i] - '0' + 1);
        }

        // larger 1 to 1
        chmin(dp[i+1][1], dp[i][1] + 9 - N[i] + '0');

        chmin(dp[i+1][0], dp[i][1] + 10 - N[i] + '0');
    }

    // for (ll i = 999998; i <= 1e6+1; i++) {
    //     cout << "i=" << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
    // }

    cout << dp[1e6+1][0] << "\n";
    
}