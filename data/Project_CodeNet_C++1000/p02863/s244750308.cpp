#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;

int fdp(const auto A, auto &dp, int N, int T){
  for(int i=1;i<=N;i++){
    int a=A[i].first;
    int b=A[i].second;
    for(int j=0;j<T;j++){
      if(j<a) dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a]+b);
    }
  }
  return 0;
}

int main(){
  int N,T;
  cin >> N >> T;

  vector<pair<int,int>> A(N+2,make_pair(0,0));
  for(int i=1;i<N+1;i++) cin >> A[i].first >> A[i].second;
  
  vector<vector<int>> dp1(N+1,vector<int>(T,0));
  vector<vector<int>> dp2(N+1,vector<int>(T,0));

  fdp(A, dp1, N, T);
  reverse(A.begin(),A.end());
  fdp(A, dp2, N, T);
  reverse(A.begin(),A.end());
  
  int ans=0;
  for(int i=1;i<=N;i++){
    int b=A[i].second;
    for(int j=0;j<T;j++){
      ans=max(ans,dp1[i-1][j]+dp2[N-i][T-1-j]+b);
    }
  }

  cout << ans << endl;
  
  return 0;
}
