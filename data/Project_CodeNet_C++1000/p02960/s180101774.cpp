#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const ll MOD = 1e9+7;
string s;
vector< vector<ll> > dp(100100, vector<ll>(15, 0));

int main() {
    cin >> s;
    int slen = s.length();

    dp[0][0] = 1;
    for(int i = 0; i < slen; ++i) {
        int cc;
        if(s.at(i) == '?') cc = -1;
        else cc = s.at(i) - '0';

        for(int j = 0; j < 10; ++j) {
            if(cc != -1 && cc != j) continue;
            for(int k = 0; k < 13; ++k) {
                dp[i+1][(k*10+j)%13] += dp[i][k];
            }
        }
        for(int j = 0; j < 13; ++j) dp[i+1][j] %= MOD;
    }

    cout << dp[slen][5] << endl;
}