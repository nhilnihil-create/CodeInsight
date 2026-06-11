#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main () {
  int N; cin >> N;
  int t = 0;

  for (int i = 1; i <= N; i++) {
    t = floor((double)i * 1.08);
    if (N == t) {
      cout << i << endl;
      break;
    }
  }
  
  if (N != t) {
    cout << ":(" << endl;
  }
  return 0;
}
