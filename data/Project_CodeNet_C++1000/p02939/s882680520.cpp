#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

  int dp[200010][3];//dp_table

int main() {
    string s;
    cin>>s;

    // 初期化
    rep(i,20010)rep(j,3) dp[i][j] = 0;

    // 初期条件
    dp[0][1]=0;dp[0][2]=0;

    // ループ
    rep(i,s.size()){
      if(i>=1&&s[i-1]!=s[i]){
        chmax(dp[i+1][1],dp[i][1]+1);
      }
      chmax(dp[i+2][2],dp[i][1]+1);
      chmax(dp[i+1][1],dp[i][2]+1);
      if(i>=2&&(s[i+1]!=s[i-1]||s[i]!=s[i-2])){
        chmax(dp[i+2][2],dp[i][2]+1);
      }
    }

    // 答え
    cout<<max(dp[s.size()][1],dp[s.size()][2])<<endl;
}