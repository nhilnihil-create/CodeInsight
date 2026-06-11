#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int dp[3001][3001] = {0};
int main(){
  int N,T;
  cin>>N>>T;
  vector<pair<int,int>> A;
  for(int i(0);i<N;i++){
    int a,b;
    cin>>a>>b;
    A.push_back({a,b});
  }
  sort(A.rbegin(),A.rend());
  for(int i(0);i<N;i++){
    for(int t(0);t<=T;t++){
      dp[i+1][t] = max(dp[i+1][t],dp[i][t]);
      if(t != 0){
        dp[i+1][t] = max(dp[i+1][t],dp[i+1][t-1]);
      }
      if(dp[i][t] == 0){
        if(t+1 <= T){
          dp[i+1][t+1] = max(dp[i+1][t+1],A[i].second);
        }
      } else {
        if(t+A[i].first <= T){
          dp[i+1][t+A[i].first] = max(dp[i+1][t+A[i].first],dp[i][t] + A[i].second);
        }
      }
    }
  }
  // for(int i(0);i<N;i++){
  //   for(int t(1);t<=T;t++){
  //     cout << dp[i][t] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[N][T] << endl;
  return 0;
}

