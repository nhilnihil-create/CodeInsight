#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int k;
  cin >> k;
  int amari = 7 % k;
  rep(i, k) {
    if (amari == 0) {
      cout << i + 1 << endl;
      return 0;
    }
    amari = (amari * 10 + 7) % k;
  }
  cout << -1 << endl;
  return 0;
}