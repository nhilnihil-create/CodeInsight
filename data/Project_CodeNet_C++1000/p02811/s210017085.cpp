#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int K, X;
  cin >> K >> X;

  if ((500 * K) >= X) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}