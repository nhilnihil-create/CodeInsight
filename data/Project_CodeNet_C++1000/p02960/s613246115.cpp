#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll dp[101010][13];

int main() {
    string s;
    cin>>s;
    int n=s.size();

    dp[0][0]=1;
    rep(dgt,n){
        rep(mo,13){
            if(s[dgt]=='?'){
                rep(nxt,10){
                    dp[dgt+1][(mo*10+nxt)%13]=(dp[dgt+1][(mo*10+nxt)%13]+dp[dgt][mo])%MOD;
                }
            }
            else{
                dp[dgt+1][(mo*10+s[dgt]-'0')%13]=(dp[dgt+1][(mo*10+s[dgt]-'0')%13]+dp[dgt][mo])%MOD;
            }
        }
    }


    cout<<dp[n][5]<<endl;
}