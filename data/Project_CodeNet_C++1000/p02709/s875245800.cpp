#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
 
using namespace std;


int main(){
  long long N;
  cin >> N;
  vector<pair<long long,long long>> V(2010);
  for(int i = 1; i<= N; i++){
    long long A;
    cin >> A;
    V[i] = make_pair((-1)*A, i);
  }
  
  sort(V.begin(), V.end());
  
  vector<vector<long long>> dp(2010, vector<long long> (2010, 0));
  
  for(int  x = 0; x<=N; x++){
    for(int y = 0; x+y<=N; y++){
      if(x==0&&y==0){
        continue;
      }
      else if(x == 0){
        dp[x][y] = dp[x][y-1]+(-1)*V[x+y-1].first*(abs(V[x+y-1].second-N+y-1));   
      }
      else if(y == 0){
        dp[x][y] = dp[x-1][y]+(-1)*V[x+y-1].first*(abs(V[x+y-1].second-x));      
      }
      else{
        dp[x][y] = max(dp[x-1][y]+(-1)*V[x+y-1].first*(abs(V[x+y-1].second-x)), dp[x][y-1]+(-1)*V[x+y-1].first*(abs(V[x+y-1].second-N+y-1))); 
      }
    }
  }
  
  /*
  for(int x = 0; x<=N; x++){
    for(int y = 0; x+y<=N; y++){
      cout << dp[x][y] << " ";
    }
    cout << endl;
  }
  
  rep(i,N){
    cout << V[i].first << " " << V[i].second << endl;
  }
  */
  
  long long ans = 0;
  for(long long x = 0; x<=N; x++){
    ans =  max(ans, dp[x][N-x]);
  }
  cout << ans << endl;
  
    
}

      
  
  


