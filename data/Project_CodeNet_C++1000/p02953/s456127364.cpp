#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long N;
  cin >> N;

  long H[N];
  for (long i = 0; i < N; i++) {
      cin >> H[i];
  }

  for (long i = 0; i < N-1; i++) {
      if (H[i] > H[i+1] ) {
          cout << "No" <<endl;
          return 0;
      }else if (H[i] < H[i+1] ) {
          H[i+1] -= 1;
      }
  }

  cout << "Yes" <<endl;
}