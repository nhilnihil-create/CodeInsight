#include <bits/stdc++.h>
using namespace std;

int main() {
  
  long long A, B, K;
  cin >> A >> B >> K;
  
  if (A >= K) {
    A = A - K;
  }
  else if (B >= K - A) {
    B = B - (K - A);
    A = 0;
  }
  else {
    A = 0;
    B = 0;
  }
  
  cout << A << " " << B << endl;
}
