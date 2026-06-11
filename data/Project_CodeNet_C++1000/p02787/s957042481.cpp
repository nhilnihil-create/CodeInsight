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
  vector<int64_t> dp(H+1, INF);
  dp.at(0)=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=H;j++){
      if(j>=A.at(i-1)){
        dp.at(j)=min(dp.at(j),dp.at(j-A.at(i-1))+B.at(i-1));
      }else{
        dp.at(j)=min(dp.at(j),(int64_t)B.at(i-1));
      }
    }
  }
  cout << dp.at(H) << endl;
  return 0;
}
