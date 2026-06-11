#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int maxH = 0;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  for (int i = 0; i < N; i++) {
    
    if (vec[i] < maxH - 1) {
      cout << "No" << endl;
      return 0;
    }
    
    maxH = max(maxH, vec[i]);
    
  }
  
  cout << "Yes" << endl;
  
}