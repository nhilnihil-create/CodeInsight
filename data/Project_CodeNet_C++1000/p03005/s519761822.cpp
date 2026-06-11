#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  if (K == 1)
    cout << 0 << endl;
  else
    cout << N - K << endl;
  return 0;
}