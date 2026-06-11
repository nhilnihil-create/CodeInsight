//
// Created by Hideaki Imamura on 2020-03-11.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (INT_MAX)
# define PI (acos(-1))
//const ll mod = 1000000007;

// 桁数は0-indexedとする
// dp[0][i]: i-1桁目まで見たとき、i-1桁目をぴったり払った時、必要なお札最小枚数
// dp[1][i]: i-1桁目まで見たとき、i-1桁目をお釣りもらって払った時、必要なお札最小枚数
ll dp[2][1000010];
string S;

int main() {
    cin >> S;
    reverse(S.begin(), S.end());
    S += '0';

    for (int i = 0; i <= S.size(); ++i) {
        dp[0][i] = dp[1][i] = INF;
    }
    dp[0][0] = 0;

    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            int x = S[i] - '0';
            x += j;
            if (x < 10) chmin(dp[0][i+1], dp[j][i] + x);
            if (x > 0) chmin(dp[1][i+1], dp[j][i] + 10 - x);
        }
    }
    cout << dp[0][S.size()] << endl;
    return 0;
}