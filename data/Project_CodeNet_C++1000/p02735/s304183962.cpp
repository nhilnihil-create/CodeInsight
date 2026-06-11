#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

// ランレングス圧縮(Run Length Encoding)
vector<pair<char,int>> RLE(string S){
  vector<pair<char,int>> p;
  int N = S.size();
  for (int i=0;i<N;i++) {
    if (S[i]==S[i+1]){
      int cnt = 1;
      char c = S[i];
      while (i+1<N && S[i]==S[i+1]) {
        i++;
        cnt++;
      }
      p.push_back({c,cnt});
    }
    else p.push_back({S[i],1});
  }

  return p;
}

int main(){
  int H, W; cin >> H >> W;
  string s[H];
  rep(i,H) cin >> s[i];
  int dp[H][W] = {};
  dp[0][0] = (s[0][0]=='#'? 1:0);

  for (int row=0;row<H;row++){
    for (int col=0;col<W;col++){
      if (row==0 && col==0) continue;

      if (col==0){
        dp[row][col] = dp[row-1][col]+(s[row-1][col]=='.' && s[row][col]=='#');
        // if(s[row-1][col]!=s[row][col]) dp[row][col] = dp[row-1][col]+1;
        // else dp[row][col] = dp[row-1][col];
      }
      else if (row==0){
        dp[row][col] = dp[row][col-1] + (s[row][col-1]=='.' && s[row][col]=='#');
        // if(s[row][col-1]!=s[row][col]) dp[row][col] = dp[row][col-1]+1;
        // else dp[row][col] = dp[row][col-1];
      }
      else {
        dp[row][col] = min(dp[row][col-1] + (s[row][col-1]=='.' && s[row][col]=='#'), \
        dp[row-1][col]+(s[row-1][col]=='.' && s[row][col]=='#'));
      } 
    }
  }
  // rep(i,H) {
    // rep(j,W) {
      // if (j>0) cout << " ";
      // cout << dp[i][j]; 
    // }
    // cout << endl;
  // }
  cout << dp[H-1][W-1] << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}
