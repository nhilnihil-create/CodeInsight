#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, M, D;
  cin >> N >> M;
  D=0;
  vector<int> A(M);
  for (int i=0; i<M; i++) {
    cin >> A[i];
  }
  for (int j=0; j<M; j++) {
    D=D+A[j];
  }
  cout << max((N-D),-1) << endl;
}