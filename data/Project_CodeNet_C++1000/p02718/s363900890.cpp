#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  int S=0;
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
    S+=A.at(i);
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  int B;
  if (S%(4*M)==0) {
    B = S/(4*M);
  }
  else {
    B = S/(4*M) + 1;
  }
  
  int C=M;
  for (int i=0; i<N; i++) {
    if (A.at(i) < B) {
      break;
    }
    C--;
  }
  if (C>0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  
}