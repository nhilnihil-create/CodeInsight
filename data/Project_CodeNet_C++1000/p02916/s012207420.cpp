#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    cin >> B[i];
  }
  for (int i=0; i<N-1; i++) {
    cin >> C[i];
  }
  
  int S=0;
  for (int i=0; i<N; i++) {
    S += B[A[i]-1];
    if (i==N-1) {continue;}
    if (A[i] + 1 == A[i+1]) {
      S += C[A[i]-1];
    }
  }
  cout << S << endl;
}