#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  vector<int> MAX(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    MAX.at(A - 1) = max(MAX.at(A - 1), H.at(B - 1));
    MAX.at(B - 1) = max(MAX.at(B - 1), H.at(A - 1));
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (H.at(i) > MAX.at(i)) {
      count++;
    }
  }
  cout << count << endl;
}