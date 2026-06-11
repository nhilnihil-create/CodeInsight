#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  int64_t res = 0;
  rep(i,n+1) {
    if (i % 3 != 0 && i % 5 != 0) res += i;
  }
  cout << res << endl;
  return 0;
}