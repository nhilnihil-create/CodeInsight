#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  N--;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> ans(N + 1);
  for (int i = 0; i < N; i++) {
    ans.at(A.at(i) - 1)++;
  }
  for (auto a : ans) cout << a << "\n";
}