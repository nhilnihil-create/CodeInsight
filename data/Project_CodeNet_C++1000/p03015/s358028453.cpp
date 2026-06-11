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

ll dp[100005][2];

int main(){
  string l;
  cin >> l;
  int n=l.size();
  dp[0][1]=1;
  rep(i, n){
    dp[i+1][0]+=3*dp[i][0];
    dp[i+1][0]%=mod;
    if(l[i]=='0'){
      dp[i+1][1]+=dp[i][1];
    } else {
      dp[i+1][1]+=2*dp[i][1];
      dp[i+1][1]%=mod;
      dp[i+1][0]+=dp[i][1];
      dp[i+1][0]%=mod;
    }
  }
  cout << (dp[n][1]+dp[n][0])%mod << endl;
  return 0;
}
