#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
char s[100005];
ll dp[100005][13];

const int MOD=1000000000+7;

int main(){
  int i,j,k;
  string s;
  cin >> s;
  ll res=0;
  n=s.size();

  dp[0][0]=1;
  for(i=0;i<n;++i){
    int c;
    if(s[i]=='?') c=-1;
    else c=s[i]-'0';

    for(j=0;j<10;++j){
      if(c!=-1 && c!=j) continue;
      for(k=0;k<13;k++){
        dp[i+1][(k*10+j)%13]+=dp[i][k];
      }
    }
    for(j=0;j<13;++j) dp[i+1][j]%=MOD;
  }
  res=dp[n][5];
  cout << res << endl;
  return 0;
}
