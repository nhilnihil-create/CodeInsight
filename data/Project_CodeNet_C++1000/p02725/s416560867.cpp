#include <bits/stdc++.h>
using namespace std;
int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {cin >> A.at(i);}
  vector<int> B(N);
  for (int i = 0; i < N - 1; i++) {B.at(i) = A.at(i + 1) - A.at(i);}
  B.at(N - 1) = A.at(0) + K - A.at(N - 1);
  int X = B.at(0);
  for (int i = 1; i < N; i++) {X = max(X, B.at(i));}
  cout << K - X << endl;
}