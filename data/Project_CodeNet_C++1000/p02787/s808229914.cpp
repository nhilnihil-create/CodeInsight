#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll H,N;cin >> H >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  ll Amax = 0;//Bsum = 0;
  for(int i=0;i<N;i++){
    cin >> A[i] >> B[i];
    Amax = max(Amax,A[i]);
    //Bsum += B[i];
  }
  ll Ha = H + Amax + 1;
  //ll INF = Bsum + 1;
  vector<vector<ll>> DP(N+1,vector<ll>(Ha,-1));
  DP[0][0] = 0;
  for(int i=1;i<=N;i++){
    for(int j=0;j<Ha;j++){
      DP[i][j] = DP[i-1][j];
      if(A[i-1]<=j){
        if(DP[i-1][j-A[i-1]]>=0){
          if(DP[i][j]>=0){
            DP[i][j] = min(DP[i][j],DP[i-1][j-A[i-1]]+B[i-1]);
          }else{
            DP[i][j] = DP[i-1][j-A[i-1]]+B[i-1];
          }
        }
        if(DP[i][j-A[i-1]]>=0){
          if(DP[i][j]>=0){
            DP[i][j] = min(DP[i][j],DP[i][j-A[i-1]]+B[i-1]);
          }else{
            DP[i][j] = DP[i][j-A[i-1]]+B[i-1];
          }
        }
      }
      //if(A[i]<=j){
      //  DP[i][j] = min(DP[i][j],DP[i-1][j-A[i-1]]+B[i-1]);
      //}
    }
  }
  ll ans = -1;
  for(int j=H;j<Ha;j++){
    if(DP[N][j]>=0){
      if(ans == -1){
        ans = DP[N][j];
      }else{
        ans = min(ans,DP[N][j]);
      }
    }
  }
  cout << ans << endl;
}