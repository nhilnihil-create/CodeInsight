#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

ll dp[100010][2]; //dp[i][j] = i桁目まで決めたときの通り数

int main() {
    string S;
    cin >> S;
    dp[0][1] = 2;
    dp[0][0] = 1;
    for(int i = 0;i < S.size() - 1;i++) {
        if(S.at(i + 1) == '0') {
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][0] = dp[i][0] * 3 % MOD;
        }
        else {
            dp[i + 1][1] = dp[i][1] * 2 % MOD;
            dp[i + 1][0] = (dp[i][1] + dp[i][0] * 3) % MOD;
        }
    }
    cout << (dp[S.size() - 1][0] + dp[S.size() - 1][1]) % MOD << endl;
}