#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int Levenshtein_Distance(char *s,char *t){
  int N = strlen(s),M = strlen(t);
  int dp[N+1][M+1];
  for(int i = 0 ; i <= N ; i++){
    dp[i][0] = i;
  }
  for(int i = 0 ; i <= M ; i++){
    dp[0][i] = i;
  }
  for(int i = 1 ; i <= N ; i++){
    for(int j = 1 ; j <= M ; j++){
      int cost = !(s[i-1] == t[j-1]);
      dp[i][j] = min(dp[i-1][j]+1,
                     min(dp[i][j-1]+1,dp[i-1][j-1]+cost));
    }
  }
  return dp[N][M];
}

int main(){
  char s[MAX],t[MAX];
  cin >> s >> t;
  cout << Levenshtein_Distance(s,t) << endl;
  return 0;
}