#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int cnt = 0;
  int p;
  rep(i, N) {
    cin >> p;
    if (i + 1 != p) cnt++;
  }
  if (cnt <= 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}