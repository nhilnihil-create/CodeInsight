#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  
  if (N == 1) cout << 0 << endl;
  
  else {
    int X = 0, Y = 0;
    for (int i = 1; i < N; i++) {
      if (S.at(i - 1) == 'R' && S.at(i) == 'L') X++;
    }
    if (S.at(0) == 'L') Y++;
    if (S.at(N - 1) == 'R') Y++;
    
    int U = 2 * X + Y;
    if (X > K) U = U - 2 * K;
    else if (X + Y > K) U = U - X - K;
    else U = 1;
    
    cout << N - U << endl;
  }
}