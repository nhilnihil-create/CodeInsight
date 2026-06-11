#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define MAX 200005
#define INF 1001001001

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll dp[100005][13];

int main(){
  string s;
  cin >> s;
  int n=s.length();
  dp[0][0]=1;
  rep(i, n){
    rep(j, 13){
      if(s[i]=='?'){
        rep(k, 10){
          dp[i+1][(j*10+k)%13]+=dp[i][j];
          dp[i+1][(j*10+k)%13]%=mod;
        }
      } else {
        int si=s[i]-'0';
        dp[i+1][(j*10+si)%13]+=dp[i][j];
        dp[i+1][(j*10+si)%13]%=mod;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}
