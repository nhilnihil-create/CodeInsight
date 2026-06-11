#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, T;
  cin >> N >> T;
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  int MINF = -10000;
  int dp1[N+1][T+1];
  int dp2[N+1][T+1];
  for(int i=0; i<N+1; i++){
    for(int j=0; j<T+1; j++){
      dp1[i][j] = 0;
      dp2[i][j] = 0;
    }
  }
  
  for(int i=0; i<N; i++){
    int a = vec.at(i).at(0);
    int b = vec.at(i).at(1);
    //dp1[i+1][a] = max(dp1[i+1][a],b);
    for(int j=0; j<T+1; j++){
      int x = MINF;
      if(j - a >= 0){
        x = dp1[i][j-a];
      }
      dp1[i+1][j] = max({dp1[i+1][j], dp1[i][j], x + b});
    }
  }
  
  
  for(int i=0; i<N; i++){
    int a = vec.at(N-i-1).at(0);
    int b = vec.at(N-i-1).at(1);
    //dp2[i+1][a] = max(dp2[i+1][a],b);
    for(int j=0; j<T+1; j++){
      int x = MINF;
      if(j - a >= 0){
        x = dp2[i][j-a];
      }
      dp2[i+1][j] = max({dp2[i+1][j], dp2[i][j], x + b});
    }
  }
  
  /*for(int i=0; i<N+1; i++){
    for(int j=0; j<T+1; j++){
      cout << dp1[i][j] << " ";
    }
    cout << endl;
  }*/
  
  
  int ans = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<T; j++){
      ans = max(ans,dp1[i][j] + dp2[N-i-1][T-j-1] + vec.at(i).at(1));
    }
  }
  cout << ans << endl;
}
