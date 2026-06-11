#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, T t){return v2<T>(r, vector<T>(c, t));}

const int MOD = 1e9+7;

int n;
string s;
v2<int> dp;
void solve(){
    cin >> s;
    n = s.length();
    dp = fill(n+1, 13, 0);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 13; j++){
            if(s[i-1] == '?'){
                for(int k = 0; k < 10; k++){
                    int nxt = (10*j + k)%13;
                    dp[i][nxt] = (dp[i][nxt] + dp[i-1][j])%MOD;
                }
            } 
            else{
                int nxt = (10*j + s[i-1]-'0')%13;
                dp[i][nxt] = (dp[i][nxt] + dp[i-1][j])%MOD;
            }
        }
    }
    
    cout << dp[n][5] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
