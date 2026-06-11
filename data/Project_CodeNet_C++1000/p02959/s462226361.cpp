#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> A(N+1), B(N);
  for (int64_t i=0; i<N+1; i++) {
    cin >> A[i];
  }
  for (int64_t i=0; i<N; i++) {
    cin >> B[i];
  }
  int64_t m=0;
  for (int64_t i=0; i<N; i++) {
    if (A[i]>=B[i]) {
      A[i]-=B[i];
      m+=B[i];
    }
    else {
      m+=A[i];
      B[i]-=A[i];
      A[i]=0;
      if (A[i+1]>=B[i]) {
        A[i+1]-=B[i];
        m+=B[i];
      }
      else {
        m+=A[i+1];
        B[i]-=A[i+1];
        A[i+1]=0;
      }
    }
  }
  cout << m << endl;
}
