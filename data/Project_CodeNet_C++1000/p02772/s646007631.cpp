#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  bool b = true;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) % 2 == 0 && A.at(i) % 3 != 0 && A.at(i) % 5 != 0) {
      b = false;
      break;
    }
  }
  if (b) {cout << "APPROVED" << endl;}
  else {cout << "DENIED" << endl;}
}