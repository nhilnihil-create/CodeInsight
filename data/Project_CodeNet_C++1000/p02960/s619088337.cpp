#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
const ll INF = 1<<29;
const ll MOD = 1e9+7;

ll dp[100010][13];

int main(){
    string s; cin >> s;
    reverse(s.begin(),s.end());
    rep(i,100010) rep(j,13) dp[i][j] = 0;
    dp[0][0] = 1;
    ll rec = 1;
    rep(i,s.size()){
        rep(j,13){
            char x = s[i];
            if(x=='?'){
                rep(k,10){
                    ll y = (k*(rec%13))%13;
                    dp[i+1][(j+y)%13] += dp[i][j];
                    dp[i+1][(j+y)%13]%=MOD;
                }
            }
            else{
                ll y = ((x-'0')*(rec%13))%13;
                dp[i+1][(j+y)%13] += dp[i][j];
                dp[i+1][(j+y)%13]%=MOD;
            }
        }
        rec*=10;
        rec%=13;
    }
    cout << dp[s.size()][5] << endl;
}