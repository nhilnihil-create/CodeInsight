#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  ll A, B, V, W, T;
  cin >> A >> V >> B >> W >> T;

  if (abs(A - B) <= (V - W) * T)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}