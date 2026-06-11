#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,N;
  cin >> H >> N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i) >> B.at(i);
  }
  const int64_t INF=1e9;
  vector<vector<int64_t> > dp(N+1,vector<int64_t>(H+1,INF));
  for(int i=0;i<=N;i++){
    dp.at(i).at(0)=0;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=H;j++){
      if(j>=A.at(i-1)){
        dp.at(i).at(j)=min(dp.at(i-1).at(j),dp.at(i).at(j-A.at(i-1))+B.at(i-1));
      }else{
        dp.at(i).at(j)=min(dp.at(i-1).at(j),(int64_t)B.at(i-1));
      }
    }
  }
  cout << dp.at(N).at(H) << endl;
  return 0;
}
