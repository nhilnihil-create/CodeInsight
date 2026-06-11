#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long MOD = 1e9+7;
string s;
vector< vector<long long> > dp(100100, vector<long long>(13, 0));

int main() {
    cin >> s;
    int slen = s.length();
    if(s.at(0) == '?') {
        for(int i = 0; i < 10; ++i) dp[0][i] = 1;
    }else {
        dp[0][s.at(0) - '0'] = 1;
    }

    // 前から順にその桁の数+13をしていくことでチェックをしていく
    for(int k = 0; k < slen-1; ++k) {
        if(s.at(k+1) == '?') {
            // 次の桁が決まっていないとき、0~9を全て試してみる
            // 一つ前の余りが0~12のときその桁にとっては10倍のあまり
            for(int i = 0; i < 13; ++i) {
                for(int j = 0; j < 10; ++j) {
                    dp[k+1][(i*10 + j) % 13] += dp[k][i];
                    dp[k+1][(i*10 + j) % 13] %= MOD;
                }
            }
        }else {
            for(int i = 0; i < 13; ++i) {
                dp[k+1][(i*10 + (s.at(k+1) - '0')) % 13] += dp[k][i];
                dp[k+1][(i*10 + (s.at(k+1) - '0')) % 13] %= MOD;
            }
        }
    }

    cout << dp[slen-1][5] << endl;
}