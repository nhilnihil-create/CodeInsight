#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, ans = 0;
  vector<int> B;
  
  cin >> N;
  
  for (int i = 0; i < N - 1; i++) {
    int inB;
    
    cin >> inB;
    
    B.push_back(inB);
  }
  
  ans += B[N - 2] + B[0];
  
  for (int i = N - 3; i >= 0; i--) {
    ans += min(B[i], B[i + 1]);
  }
  
  cout << ans << endl;
  
  return 0;
}