#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using P = pair<int, int>;
const int INF = 1001001001;

int main() {
  string s;
  cin>>s;
  int dp[1000005][2];
  rep(i,1000005){
    rep(j,2){
      dp[i][j]=INF;
    }
  }
  reverse(s.begin(),s.end());
  s+='0';
  dp[0][0]=0;
  rep(i,s.size()){
    rep(j,2){
      rep(k,10){
        int a=s[i]-'0';
        int b=k;
        if(j==1) a++;
        int c=b-a; 
        if(c>=0){
          dp[i+1][0]=min(dp[i][j]+b+c,dp[i+1][0]);
        }else{ 
          c+=10;
          dp[i+1][1]=min(dp[i][j]+b+c,dp[i+1][1]);
        }
      }
      
    }
  }
  cout<<dp[s.size()][0]<<endl;
}
