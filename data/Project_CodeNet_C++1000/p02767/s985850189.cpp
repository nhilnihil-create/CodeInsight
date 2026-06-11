#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  vector<int> X(N);
  for(int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  
  sort(X.begin(), X.end());
  for(int i = 0; i < N; i++) {
  }

  int L, ans = 0;
  
  for(int i = X.at(0); i <= X.at(N-1); i++) {
    L = 0;
    
    for(int j = 0; j < N;j++) {
      L += (X.at(j)-i)*(X.at(j)-i);
    if(i == X.at(0) && j == N-1) ans = L; 
    }
    
    if(i > X.at(0) && L < ans) ans = L;
  }
  
  cout << ans << endl;
  
}