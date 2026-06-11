#include <iostream>
#include <vector>
using namespace std;

int main(){
  int MOD = 1e9 + 7;
  int N, M;
  cin >> N >> M;
  
  vector<int> dp(N+1);
  for(int i = 0;i < M;i++){
    int a;
    cin >> a;
    
    dp.at(a) = -1;
  }
  
  dp.at(0) = 1;
  for(int i = 1;i <= N;i++){
    if(dp.at(i) == -1){
      dp.at(i) = 0;
      continue;
    }
    if(i == 1){
      dp.at(i) = 1;
      continue;
    }
    dp.at(i) = (dp.at(i-1) + dp.at(i-2)) % MOD;
  }
  
  cout << dp.at(N) << endl;
  
  return 0;
}