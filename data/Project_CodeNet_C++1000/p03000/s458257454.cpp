#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L.at(i);
  vector<int> P(N+1);
  P.at(0) = 0;
  for (int i = 1; i < N+1; i++) {
    P.at(i) = P.at(i-1) + L.at(i-1);
  }
  int count = 0;
  for (int i = 0; i < N+1; i++) {
    if (P.at(i) <= X) {
      count++;
    }
  }
  cout << count << endl;
}