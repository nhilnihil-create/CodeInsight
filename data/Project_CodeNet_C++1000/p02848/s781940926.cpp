#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;

  rep(i, S.size()) {
    int x = S[i] - 'A';
    x = (x + N) % 26;
    cout << (char)('A' + x);
  }
  return 0;
}