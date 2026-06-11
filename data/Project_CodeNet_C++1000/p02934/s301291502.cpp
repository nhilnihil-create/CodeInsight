#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  double r;
  r=1/A.at(0);
  if (N>=2) {
    for (int j=1; j<N; j++) {
      r=r+(1/(A.at(j)));
    }
  }
  cout << 1/r << endl;
}