#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  set<int> SE;
  for (int i = 0; i < K; i++) {
    int D;
    cin >> D;
    for (int j = 0; j < D; j++) {
      int A;
      cin >> A;
      SE.insert(A);
    }
  }
  cout << N - SE.size() << "\n";
}