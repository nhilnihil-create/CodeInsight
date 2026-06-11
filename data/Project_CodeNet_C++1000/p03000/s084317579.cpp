#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  
  int L[N];
  for (int i = 0; i < N; i++) cin >> L[i];
  
  int D = 0;
  int ans = 1;
  
  for (int i = 0; i < N; i++) {
    D += L[i];
    if (D <= X) {
      ans++;
    } else {
      break;
    }
  }
  
  cout << ans << endl;
    
}