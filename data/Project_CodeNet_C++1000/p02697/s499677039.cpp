#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) {
    if (N % 2 == 0) {
      if (i % 2 == 0) {
        int j = i / 2 + 1;
        cout << j << ' ' << N + 1 - j << endl;
      } else {
        int c = N / 2 + 1;
        int d = (i + 1) / 2;
        cout << c - d << ' ' << c + d << endl;
      }
    } else {
      cout << i + 1 << ' ' << N - i << endl;
    }
  }
}
  
