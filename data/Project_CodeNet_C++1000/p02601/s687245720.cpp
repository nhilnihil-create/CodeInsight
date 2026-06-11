#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int ans = 0;
  if(A >= B) {
    for(int i = 0; i < 100; i++) {
      B = B * 2;
      ans++;
      if(A < B) {
        break;
      }
    }
  }
  if(B >= C) {
    for(int i = 0; i < 100; i++) {
      C = C * 2;
      ans++;
      if(B < C) {
        break;
      }
    }
  }
  if(ans > K) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}