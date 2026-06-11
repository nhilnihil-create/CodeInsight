#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  
  int max = 0;
  while(K>0) {
    if (A>0) {
      max += 1;
      A--;
    } else if (B>0) {
      B--;
    } else {
      max -= 1;
      C--;
    }
    K--;
  }
  cout << max << endl;
  return 0;
}
