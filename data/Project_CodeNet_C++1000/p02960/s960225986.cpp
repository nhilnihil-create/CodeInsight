#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
//dp[先頭i文字][あまりj] = 組み合わせ何通り

ll add(ll &a, ll b){
    a += b;
    if(a>mod) a-=mod;
}

int main() {
    string s;
    cin >> s;
    vector<vector<ll>> dp(s.size()+1, vector<ll>(13, 0));
    dp[0][0] = 1;
    rep(i,s.size()){
        rep(j,13){
            if(s[i]=='?'){
                rep(k,10){
                    add(dp[i+1][(j*10+k)%13], dp[i][j]);
                }
            }
            else{
                int k = s[i]-'0';
                add(dp[i+1][(j*10+k)%13], dp[i][j]);
            }
        }
    }
    cout << dp[s.size()][5] << endl;
    return 0;
}