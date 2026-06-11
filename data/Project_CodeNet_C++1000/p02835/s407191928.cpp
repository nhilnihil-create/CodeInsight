#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  if (A1 + A2 + A3 >= 22) {
    cout << "bust" << endl;
  } else {
    cout << "win" << endl;
  }
 
  return 0;
}