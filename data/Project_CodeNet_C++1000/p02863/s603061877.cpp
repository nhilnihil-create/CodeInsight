#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
  int i,j,N,T;
  cin >> N >> T;
  vector<pair<int,int>> A(N);
  int a,b;
  for(i=0; i<N; i++){
    cin >> a >> b;
    A[i] = make_pair(a,b);
  }
  sort(A.begin(),A.end());
  vector<vector<int>> dp(N,vector<int>(T));
  vector<vector<int>> dp2(N,vector<int>(T));
  for(i=0; i<T; i++){
    dp[0][i] = A.at(0).second;
    if(i<A.at(0).first) dp2[0][i] = 0;
    else dp2[0][i] = A.at(0).second;
  }
  int tmp;
  for(i=0; i<T; i++){
    for(j=1; j<N; j++){
      dp[j][i] = max(dp[j-1][i],dp2[j-1][i]+A.at(j).second);
      if(i>=A.at(j).first) tmp = dp2[j-1][i-A.at(j).first] +A.at(j).second;
      else tmp = 0;
      dp2[j][i] = max(dp2[j-1][i], tmp);
    }
  }
  cout << dp[N-1][T-1];
  return 0;
}