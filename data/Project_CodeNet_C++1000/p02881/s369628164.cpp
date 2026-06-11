#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N;
  cin >> N;
  int64_t B;
  for(int64_t A = sqrt(N) + 1; A > 0; A--) {
    if(N % A == 0) {
      B = A;
      break;
    }
  }
  int64_t C = N / B;
  cout << B + C - 2 << endl;
}