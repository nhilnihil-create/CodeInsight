#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int dp[1005][10005];

int main(){
  int h, n;
  cin >> h >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n){
    cin >> a[i] >> b[i];
  }
  rep(i, n+1)rep(j, 10005){
    dp[i][j]=INF;
  }
  dp[0][0]=0;
  rep(i, n){
    rep(j, 10005){
      if(j-a[i]<0){
        dp[i+1][j]=min(dp[i+1][0]+b[i], dp[i][j]);
      } else {
        dp[i+1][j]=min(dp[i+1][j-a[i]]+b[i], dp[i][j]);
      }
    }
  }
  cout << dp[n][h] << endl;
  return 0;
}
