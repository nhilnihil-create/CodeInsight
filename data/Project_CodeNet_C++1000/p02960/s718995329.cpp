#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const ll MOD=1e9+7;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    string s;
    cin >> s;
    int n=s.size();
    int dp[100005][13]={};

    dp[0][0]=1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 13; j++) {
            if(s[i]=='?'){
                for(int k = 0; k < 10; k++) {
                    dp[i+1][(j*10+k)%13]+=dp[i][j];
                    dp[i+1][(j*10+k)%13]%=MOD;
                }
            }
            else{
                int k=s[i]-'0';
                dp[i+1][(j*10+k)%13]+=dp[i][j];
                dp[i+1][(j*10+k)%13]%=MOD;
            }
        }
    }
    cout << dp[n][5] << "\n";
    return 0;
}