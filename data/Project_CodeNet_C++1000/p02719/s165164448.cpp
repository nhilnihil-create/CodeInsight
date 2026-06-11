#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N, K;
  cin >> N >> K;
  int64_t A = N % K;
  int64_t B = K - A;
  if (A < B) {
    cout << A << endl;
  }
  else {
    cout << B << endl;
  }
}