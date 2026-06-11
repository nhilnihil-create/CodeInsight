#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

const ll MOD = 1000000007;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(),s.end());
    vector<vector<int>> dp(100005,vector<int>(13,0));
    dp.at(0).at(0) = 1;
    int mul = 1;
    rep(i,n){
        if(s.at(i) == '?'){
            rep(j,10){
                rep(k,13){
                    dp.at(i+1).at((j*mul + k)%13) += dp.at(i).at(k);
                    dp.at(i+1).at((j*mul + k)%13) %= MOD;
                }
            }
        }else{
            int c = s.at(i) - '0';
            rep(k,13){
                dp.at(i+1).at((c*mul + k)%13) += dp.at(i).at(k);
                dp.at(i+1).at((c*mul + k)%13) %= MOD;
            }
        }
        mul *= 10;
        mul %= 13;
    }
    cout << dp[n][5] << endl;
}