#include<iostream>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  long sum = 0; for (int i = 0; i < N; i++) sum += A[i];
  long C[2*N+1]; C[0] = 0;
  for (int i = 0; i < 2*N; i++) C[i+1] = C[i] + A[(2*i+1)%N];
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    int j;
    if (i % 2) j = (N+1)/2 + i/2;
    else j = i/2;
    cout << sum - 2 * (C[j+(N-1)/2] - C[j]);
  }
  cout << endl;
}