#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int cnt = 0;
  while (A >= B) {
    cnt++;
    B *= 2;
  }
  while (B >= C) {
    cnt++;
    C *= 2;
  }
  if (cnt <= K)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}