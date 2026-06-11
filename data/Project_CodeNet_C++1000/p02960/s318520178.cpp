#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    vector<vector<int>> dp(100100,vector<int>(14,0));
    dp[0][0] = 1;
    for(int i = 0;i < s.size(); i++){
        for(int j = 0;j < 13; j++){
            if(s[i] == '?'){
                for(int k= 0; k < 10; k++){
                    dp[i+1][(j*10 + k) % 13] += dp[i][j];
                    dp[i+1][(j*10 + k) % 13] %= mod;
                }
            }else{
                int k = s[i] - '0';
                dp[i+1][(j*10 + k) % 13] += dp[i][j];
                dp[i+1][(j*10 + k) % 13] %= mod;
            }
        }
    }
    cout << dp[s.size()][5] << endl;
    return 0;
}