#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    string s;cin >>s;
    ll n=s.size();
    vector<vector<ll>>dp(n+1,vector<ll>(13,0));
    dp[0][0]=1;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='?'){
            for (int j = 0; j < 13; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ll f=((j*10)%13+k)%13;
                    dp[i+1][f]+=dp[i][j];
                    dp[i+1][f]%=mod;
                }
            }
        }
        else {
            ll now=s[i]-'0';
            for (int j = 0; j < 13; ++j) {
                ll k=((j*10)%13+now)%13;
                dp[i+1][k]+=dp[i][j];
                dp[i+1][k]%=mod;
            }
        }
    }
    cout <<dp[n][5]<<endl;
    return 0;
}
