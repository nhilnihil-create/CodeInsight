#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  int sum = 1;
  while (sum < B) {
    sum = sum + A - 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}