#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

char s[N+9];
int n;

void into(){
  scanf("%s",s+1);
  n=strlen(s+1);
}

int dp[N+9][2];

void Get_dp(){
  dp[1][0]=1;
  for (int i=2;i<=n;++i){
	dp[i][0]=max(dp[i-1][1]+1,s[i-1]==s[i]?0:dp[i-1][0]+1);
	dp[i][1]=max(dp[i-2][0]+1,i<=3||s[i-3]==s[i-1]&&s[i-2]==s[i]?0:dp[i-2][1]+1);
  }
}

void work(){
  Get_dp();
}

void outo(){
  printf("%d\n",max(dp[n][0],dp[n][1]));
}

int main(){
  into();
  work();
  outo();
  return 0;
}