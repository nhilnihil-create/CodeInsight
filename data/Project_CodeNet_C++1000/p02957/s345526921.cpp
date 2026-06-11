#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, B;
  cin >> A >> B;
  if ((max(A, B) + min(A, B)) % 2LL == 0) {
    cout << (max(A, B) + min(A, B)) / 2LL << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}