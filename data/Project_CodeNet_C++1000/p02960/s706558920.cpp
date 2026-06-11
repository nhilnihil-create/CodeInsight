#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int N=s.size();
  vector<vector<int64_t>>dp(100005,vector<int64_t>(13));
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<13;j++){
      if(s[i]=='?'){
        for(int k=0;k<10;k++){
          dp[i+1][(10*j+k)%13]+=dp[i][j];
          dp[i+1][(10*j+k)%13]%=mod;
        }
      }
      else{
        dp[i+1][(10*j+s[i]-'0')%13]+=dp[i][j];
        dp[i+1][(10*j+s[i]-'0')%13]%=mod;

      }
    }
  }
  cout<<dp[N][5]<<endl;
  return 0;  
}