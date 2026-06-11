#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int K;
  cin >> K;

  int ans = -1;
  int num = 0;
  rep(i, 1100000) {
    num = 10 * num + 7;
    num %= K;
    if (num == 0) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}