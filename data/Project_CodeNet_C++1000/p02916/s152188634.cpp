#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N-1);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int j=0; j<N; j++) {
    cin >> B[j];
  }
  for (int k=0; k<N-1; k++) {
    cin >> C[k];
  }
  for (int l=0; l<N; l++) {
    ans=ans+B[l];
  }
  for (int m=0; m<N-1; m++) {
    if (A[m]+1==A[m+1]) {
      ans=ans+C[A[m]-1];
    }
  }
  cout << ans << endl;
}