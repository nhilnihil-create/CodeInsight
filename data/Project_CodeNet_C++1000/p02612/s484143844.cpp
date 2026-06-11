#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  cout << 1000 * (N / 1000 + min(1, N % 1000)) - N << endl;
  return 0;
}
