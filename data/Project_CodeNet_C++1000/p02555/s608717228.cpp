#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int s;
  cin>>s;
  vector<int>dp(2005);//cout<<s<<endl;
  dp[0]=1;
  for(int i=0;i<=s;i++){
    for(int now=3;now<=2000;now++){
      if(i+now<=2000){(dp[i+now]+=dp[i])%=mod;}
    }
  }
  cout<<dp[s]<<endl;
  return 0;
}