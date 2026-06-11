#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  queue<long long> q;
  for (int i = 1; i <= 9; i++) {
    q.push(i);
  }
  long long n;
  while (k--) {
    n = q.front();
    q.pop();
    if (n % 10 != 0) {
      q.push(10 * n + n % 10 - 1);
    }
    q.push(10 * n + n % 10);
    if (n % 10 != 9) {
      q.push(10 * n + n % 10 + 1);
    }
  }
  cout << n << '\n';
  return 0;
}