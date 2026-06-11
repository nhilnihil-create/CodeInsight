#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll p = 1000000007LL;

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(13));
    dp[0][0] = 1;
    rep(i,n){
        int c;
        if(s.at(i) == '?') c = -1;
        else c = s.at(i) - '0';
        rep(j,10){
            if(c != -1 && c != j) continue;
            rep(k,13){
                int e = (k * 10 + j) % 13;
                dp[i+1][e] += dp[i][k];
            }
            rep(k,13){
                dp[i+1][k] = dp[i+1][k] % p;
            }
        }
    }

    cout << dp[n][5] << endl;
    return 0;
}