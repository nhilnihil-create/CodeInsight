#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 9;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q;
  cin >> Q;
  while (Q--) {
    int b;
    cin >> b;
    for (int i = 0; i < N; i++) {
      if (A.at(i) == b) A.at(i) = -1;
    }
  }
  bool b = 0;
  if (A.at(0) + A.at(1) + A.at(2) == -3) b = 1;
  if (A.at(3) + A.at(4) + A.at(5) == -3) b = 1;
  if (A.at(6) + A.at(7) + A.at(8) == -3) b = 1;
  if (A.at(0) + A.at(3) + A.at(6) == -3) b = 1;
  if (A.at(1) + A.at(4) + A.at(7) == -3) b = 1;
  if (A.at(2) + A.at(5) + A.at(8) == -3) b = 1;
  if (A.at(0) + A.at(4) + A.at(8) == -3) b = 1;
  if (A.at(2) + A.at(4) + A.at(6) == -3) b = 1;
  cout << ((b) ? "Yes" : "No") << "\n";
}