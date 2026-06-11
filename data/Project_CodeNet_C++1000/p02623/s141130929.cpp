#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, M, K, a, b;
  cin >> N >> M >> K;
  vector<int64_t> A(N+1);
  vector<int64_t> B(M+1);
  for (int64_t i=1; i<=N; i++) {
    cin >> a;
    A.at(i) = a + A.at(i-1);
  }
  for (int64_t i=1; i<=M; i++) {
    cin >> b;
    B.at(i) = b + B.at(i-1);
  }
  
  int64_t C=0, j=M;
  for (int i=0; i<=N; i++) {
    if (A.at(i) > K) {break;}
    while (B.at(j) > K - A.at(i)) {
      //cout << i << " " << j << " " << C << endl;
      j--;
    }
    C = max(C, i+j);
  }
  cout << C << endl;
}