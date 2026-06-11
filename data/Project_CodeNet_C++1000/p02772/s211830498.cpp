#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N;
  T=0;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int j=0; j<N; j++) {
    if (A[j]%2==1) {
      T=T+1;
    }
    else {
      if (A[j]%3==0||A[j]%5==0) {
        T=T+1;
      }
    }
  }
  if (T==N) {
    cout << "APPROVED" << endl;
  }
  else {
    cout << "DENIED" << endl;
  }
}