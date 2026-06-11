#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int dp[100005][13];
const int mod = 1e9 + 7;

int main(){
    string s; cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 13; j++){
            if(s[i] == '?'){
                for(int k = 0; k <= 9; k++){
                    (dp[i+1][(j * 10 + k) % 13] += dp[i][j]) %= mod; 
                }
            }else{
                int k = s[i] - '0';
                (dp[i+1][(j * 10 + k) % 13] += dp[i][j]) %= mod; 
            }
        }
    }
    cout << dp[s.size()][5] << endl;
}