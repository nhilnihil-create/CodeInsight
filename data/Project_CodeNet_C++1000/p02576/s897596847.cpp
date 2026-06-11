#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, T, ans;
  cin >> N >> X >> T;
  ans = (N / X) * T;
  if (N % X != 0) {
    ans += T;
  }
  cout << ans << endl;
}