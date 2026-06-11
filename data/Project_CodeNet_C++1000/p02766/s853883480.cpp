#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  long n;int  k;
  cin >> n >> k;
  int res = 0;
  while (n > 0) {
    n /= k;
    res++;
  }
  cout << res << endl;
  return 0;
}

