#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = n % 10;
  string res;
  if (r == 3) {
    res = "bon";
  } else if (r == 0 || r == 1 || r== 6 || r == 8) {
    res = "pon";
  } else {
    res = "hon";
  }
  cout << res << endl;

  return 0;
}

