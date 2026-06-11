#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[5005][5005];

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(s[i]==s[j]) dp[i][j] = dp[i+1][j+1] + 1;
    }
  }
  int ans = 0;
  rep(i,n){
    rep(j,n){
      if(i>=j) continue;
      int ans1 = min(dp[i][j],j-i);
      ans = max(ans,ans1);
    }
  }
  cout << ans << endl;
  return 0;
  
}