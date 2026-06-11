#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1e9 + 7;

int main(void){
    int s;
    cin >> s;
    vector<int> dp(s + 1);
    fill(dp.begin(), dp.end(), 0);
    dp[0] = 1;
    for(int i = 3; i <= s; ++i){
        for(int j = i - 3; j >= 0; --j){
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }
    cout << dp[s] << endl;
    return 0;
}