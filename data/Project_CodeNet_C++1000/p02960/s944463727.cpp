#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int mod = 1000000007;
int main() {
    string s;
    cin >> s;
    int dp[100020][13] = {0};
    dp[0][0] = 1;
    int n = s.size();
    rep(i,n) {
        rep(j,13) {
            if(s[i] == '?') {
                for(int b = 0;b<=9;b++) {
                    int j2 = (j*10 + b)%13;
                    dp[i+1][j2] = (dp[i+1][j2] + dp[i][j])%mod;
                }
            } else {
                int j2 = (j*10 + (s[i] - '0'))%13;
                dp[i+1][j2] = (dp[i+1][j2] + dp[i][j])%mod;
            }
        }
    }
    cout << dp[n][5] << endl;
}