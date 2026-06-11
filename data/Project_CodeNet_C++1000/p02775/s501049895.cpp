#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int dp[1000005][2];

int main(){
  string s;
  cin >> s;
  int n=s.size();
  dp[0][0]=0;dp[0][1]=1;
  rep(i, n){
    int si=s[i]-'0';
    dp[i+1][0]=min(dp[i][0]+si, dp[i][1]+(10-si));
    dp[i+1][1]=min(dp[i][0]+si+1, dp[i][1]+(9-si));
  }
  cout << dp[n][0] << endl;
  return 0;
}
