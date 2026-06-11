#include <bits/stdc++.h>
using namespace std;

int nth_bit(int xorr, int k) {
  return (xorr >> k) & 1;
}

int res[200010];
int main() {
  int N;
  cin >> N;
  int A[N];
  int xorr = 0;
  for (int i = 0; i < N; i++ ) {
    cin >> A[i];
    xorr ^= A[i]; 
  }

  for (int k = 0; k < 32; k++) {
    if (nth_bit(xorr ^ A[0], k) != nth_bit(A[0], k)) {
      for (int i = 0; i < N; i++) {
        res[i] += (!nth_bit(A[i], k) << k);
      }  
    } else {
      for (int i = 0; i < N; i++) {
        res[i] += (nth_bit(A[i], k) << k);
      } 
    }
  }
  for (int i = 0; i < N; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
