#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  int A = 1;
  int B = K;
  for (int i = 0; i < 40; i++) {
    if (A <= N && N < B) {
      cout << i + 1 << endl;
      break;
    }
    A *= K;
    B *= K;
  } 
      
}
