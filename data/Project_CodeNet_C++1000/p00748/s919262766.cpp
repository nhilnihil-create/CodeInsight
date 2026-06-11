#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int INF = 1e8;
int dp[MAX_N+1],dp2[MAX_N+1];

int main(){
  fill(dp,dp+MAX_N,INF);
  fill(dp2,dp2+MAX_N,INF);
  dp[0] = dp2[0] = 0;

  int n = 1, pil = 1;
  do{
    for(int i=0;i<=MAX_N-pil;i++){
      dp[i+pil] = min(dp[i+pil], dp[i] + 1);
    }
    if(pil % 2){
      for(int i=0;i<=MAX_N-pil;i++){
	dp2[i+pil] = min(dp2[i+pil], dp2[i] + 1);
      }
    }

    n++;
    pil = n*(n+1)*(n+2)/6;
  }while(pil<=MAX_N);

  while(cin >> n, n){
    cout << dp[n] << " " << dp2[n] << endl;
  }
}