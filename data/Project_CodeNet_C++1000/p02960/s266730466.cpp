#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
ll dp[N][13];
ll mod = 1e9 + 7;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("WALKING.INP", "r")){
                freopen("WALKING.INP", "r", stdin);
                freopen("WALKING.OUT", "w", stdout);
        }
        string s;
        cin >> s;
        ll n = s.length();
        s = " " + s;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++){
                for (int j = 0; j < 13; j++){
                        if (s[i] == '?'){
                                for (int k = 0; k < 10; k++){
                                        dp[i][(j * 10 + k) % 13] += dp[i - 1][j];
                                        dp[i][(j * 10 + k) % 13] %= mod;
                                }
                        } else {
                                dp[i][(j * 10 + (s[i] - '0')) % 13] += dp[i - 1][j];
                                dp[i][(j * 10 + (s[i] - '0')) % 13] %= mod;
                        }
                }
        }
        cout << dp[n][5];
}
