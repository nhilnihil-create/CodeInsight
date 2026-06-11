#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  vector<int> C(N-1);
  for (int i = 0; i < N-1; i++) {
    cin >> C.at(i);
  }
  
  int sat = 0;
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      if (A.at(i) == A.at(i - 1) + 1) {
        sat = sat + C.at(A.at(i-1) - 1) + B.at(A.at(i) - 1);
      }
      else {
        sat = sat + B.at(A.at(i) - 1);
      }
    }
    else {
      sat = sat + B.at(A.at(0) - 1);
    }
  }
  cout << sat << endl;
}
