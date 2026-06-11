#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int N, D;
  vector<vector<int>> X(10, vector<int>(10));
  
  cin >> N >> D;
  
  for(int i = 0;i < N;i++) for(int j = 0;j < D;j++) cin >> X.at(i).at(j);
  
  int ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = i + 1;j < N;j++){
      int sum = 0;
      for(int k = 0;k < D;k++) sum += pow(X.at(i).at(k) - X.at(j).at(k), 2);
      for(int j = 1;j * j <= sum;j++) if(j * j == sum) ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}