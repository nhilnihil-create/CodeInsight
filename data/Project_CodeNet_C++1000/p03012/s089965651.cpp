#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> W(N);
  cin >> W.at(0);
  for(int i = 1;i < N;i++){
    int w;
    cin >> w;
    
    W.at(i) = W.at(i-1) + w;
  }
  
  int ans = 100000;
  for(int i = 1;i < N;i++){
    int S1 = W.at(i-1), S2 = W.at(N-1) - S1;
    ans = min(ans, abs(S1 - S2));
  }
  
  cout << ans << endl;
  
  return 0;
}