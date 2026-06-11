#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, N, X = 0;
  cin >> H >> N;
  
  vector<int> A(N);
  
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    X += A.at(i);
  }
  
  if(X >= H) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}