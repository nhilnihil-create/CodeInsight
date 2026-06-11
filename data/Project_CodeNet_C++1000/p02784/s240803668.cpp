#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int H, N, P;
  cin >> H >> N;
  P=0;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int j=0; j<N; j++) {
    P=P+A[j];
  }
  if (H<=P) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
