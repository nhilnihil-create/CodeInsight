#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  int res;
  if (n >= 10) res = r;
  else res = r + 100*(10-n);
  cout << res << endl;
  return 0;
}

