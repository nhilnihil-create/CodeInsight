#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  for(int i = 1; i < 2 * N; i++) {
    if(0 <= i * 1.08 - N && i * 1.08 - N < 1) {
      cout << i << endl;
      break;
    }
    if(i == 2 * N - 1) {
      cout << ":(" << endl;
    }
  }
}