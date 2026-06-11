#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  const long long INF = 1e18;
  int N, K;
  cin >> N >> K;
  vector<int> H(N+1);
  for(int i = 0; i < N; ++i) cin >> H[i];
  vector<int> h = H;
  sort(h.begin(), h.end());
  h.erase(unique(h.begin(), h.end()),h.end());
  int m = h.size();
  map<int,int> I;
  for(int i = 0; i < m; ++i)
    I[h[i]] = i;
  vector<vector<long long>> dp(K+1,vector<long long>(N+1,INF));
  dp[0][0] = 0;
  for(int i = 0; i < N; ++i){
    int idx = I[H[i]];
    vector<vector<long long>> dp_(K+1,vector<long long>(N+1,INF));
    for(int j = 0; j <= K; ++j){
      for(int l = 0; l < m; ++l){
        if(h[l] < h[idx])
          dp_[j][idx] = min(dp_[j][idx],dp[j][l]+h[idx]-h[l]);
        else
          dp_[j][idx] = min(dp_[j][idx],dp[j][l]);
      }
      //change i-th height
      if(j == K) continue;
      vector<long long> mi(m+1,INF);
      for(int l = m-1; l >= 0; --l){
        mi[l] = min(dp[j][l],mi[l+1]);
      }
      long long s = INF;
      for(int l = 0; l < m; ++l){
        dp_[j+1][l] = min(dp_[j+1][l],mi[l]);
        if(l > 0){
          s += h[l]-h[l-1];
        }
        s = min(s,dp[j][l]);
        dp_[j+1][l] = min(dp_[j+1][l],s);
      }
    }
    swap(dp_,dp);
  }
  long long ans = INF;
  for(int i = 0; i <= K; ++i){
    for(int j = 0; j < m; ++j){
      //cerr << i << " " << j <<  " "<< dp[i][j] << endl;
      ans = min(ans,dp[i][j]);
    }
  }
  cout << ans << endl;
}
