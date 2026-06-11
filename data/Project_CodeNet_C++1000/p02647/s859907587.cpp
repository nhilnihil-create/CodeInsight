#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (auto& a: A) cin >> a;
  for (int i = 0; i < K; i++) {
    vector<int> B(N+1);
    for (int j = 0; j < N; j++) {
      B[max(j - A[j], 0)]++;
      B[min(j + A[j] + 1, N)]--;
    }
    for (int j = 1; j <= N; j++) {
      B[j] += B[j-1];
    }
    B.pop_back();
    swap(A, B);
    if (*min_element(A.begin(), A.end()) == N) break;
  }
  for (int i = 0; i < N; i++) {
    cout << A[i] << " \n"[i==N-1];
  }
}
