#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,mod=1000000007;
  cin >> N >> M;
  vector<bool> A(N+1,false);//trueは壊れている
  for(int i=0;i<M;i++){
    int B;
    cin >> B;
    A.at(B)=true;
  }
  vector<int> dp(N+1);
  dp.at(0)=1;
  for(int i=0;i<N;i++){
    if(!A.at(i+1)){
      dp.at(i+1)+=dp.at(i);
      dp.at(i+1)%=mod;
    }
    if(i!=N-1 && !A.at(i+2)){
      dp.at(i+2)+=dp.at(i);
      dp.at(i+2)%=mod;
    }
  }
  cout << dp.at(N) << endl;
}