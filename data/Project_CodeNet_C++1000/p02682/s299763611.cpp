#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, C, K, ans = 0;
  cin >> A >> B >> C >> K;
  
  if (A < K) {
    K = K - A;
    ans = A;
  } else {
    ans = K;
    K = 0;
  }

  if (K != 0) K = K - B;
  
  if (K != 0) {
    if (C > K) ans = ans - K;
    else ans = ans - C;
  }
    
  cout << ans << endl;
}