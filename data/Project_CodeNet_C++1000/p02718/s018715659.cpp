#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, M, S;
  cin >> N >> M;
  S=0;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    S=S+A[i];
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  if (4*M*A[M-1]>=S) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
