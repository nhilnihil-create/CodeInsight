#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int S[2010], T[2010];

long long int dp[2100][2100];
 
int main() {
  
    cin >> N >> M;
  
    memset(dp, 0, sizeof(0));
  
    for (int i = 0; i < N; ++i) cin >> S[i],dp[i][0]=1;
  
    for (int i = 0; i < M; ++i) cin >> T[i],dp[0][i]=1;
  
  dp[N][0] = 1,dp[0][M] = 1;
  
 for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
     dp[i][j] = dp[i-1][j]+ dp[i][j-1] - dp[i-1][j-1];
      
        if(S[i-1] == T[j-1]){
      dp[i][j]+=dp[i-1][j-1];
        }
			dp[i][j]+=1000000007;
      
			dp[i][j]%=1000000007;
		}
	}
 
  
    cout << dp[N][M] % 1000000007 << endl;
}
