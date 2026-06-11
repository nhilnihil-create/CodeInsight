#include <bits/stdc++.h>
using namespace std;
int main() {
  int S, T; cin >> S >> T;
  int N; cin >> N;
  cout << (N + max(S, T) - 1) / max(S, T) << endl;
}