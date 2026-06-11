#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0, leftSide = 0, rightSide = 0;
  
  int64_t minDif = 2020202020, tmp;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) {
    
    cin >> vec[i]; sum += vec[i];
    
  }
  
  for (int i = 0; i < N - 1; i++) {
    
    leftSide += vec[i]; rightSide = sum - leftSide;
    
    tmp = abs(leftSide - rightSide);
    
    minDif = min(minDif, tmp);
    
  }
  
  cout << minDif << endl;
  
}