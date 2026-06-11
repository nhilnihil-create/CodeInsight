#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  
  int A = 0;
  int count = 0;
  
  for (int i = 0; i < N; i++) {
    A += D * 2 + 1;
    count++;
    if (A >= N) {
      break;
    }
  }
  cout << count << endl;
}
