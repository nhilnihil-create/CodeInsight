#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  long long T = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    T += A[i];
  }
  vector<long long> S(N - 1);
  S[0] = A[0];
  for (int i = 0; i < N - 1; i++){
    S[i + 1] = S[i] + A[i + 1];
  }
  long long m = 1e16;
  for (int i = 0; i < N - 1; i++){
    m = min(m, abs((T - S[i]) - S[i]));
  }
  cout << m;
}