#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int max = 0, max2 = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) >= max) {
      max2 = max;
      max = A.at(i);
    }
    else if (max2 < A.at(i)) {
      max2 = A.at(i);
    }
  }
  for (int i = 0; i < N; i++) {
    if (A.at(i) < max) {
      cout << max << endl;
    }
    else {
      cout << max2 << endl;
    }
  }
}