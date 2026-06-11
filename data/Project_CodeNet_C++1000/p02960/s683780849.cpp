#include <iostream>
#include<vector>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;

const ll mod = 1e9+7;


int main() {
    string s;
    cin>>s;
    vector<vector<ll>>dp(s.length()+1,vector<ll>(13));
    dp[0][0] = 1;
    int mul = 1;
    for(int i = 0; i < s.length(); i++) {
        if(s[s.length()-1-i]=='?') {
            rep(j,10) {
                rep(k,13) {
                    dp[i+1][(j*mul+k)%13] += dp[i][k];
                    dp[i+1][(j*mul+k)%13] %= mod;
                }
            }
        }
        else {
            int j = (int)(s[s.length()-1-i]-'0');
            rep(k,13) {
                dp[i+1][(j*mul+k)%13] += dp[i][k];
                dp[i+1][(j*mul+k)%13] %= mod;
            }
        }
        mul *= 10;
        mul %= 13;
    }
    cout<<dp[s.length()][5]<<endl;
    

    return 0;
}
