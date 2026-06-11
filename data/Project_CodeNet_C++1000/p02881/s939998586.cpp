#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll n, a, b, cnt, num;
  cnt = LONG_LONG_MAX;
  cin >> n;
  for (a = 1; a <= sqrt(n); a++)
    if (n % a == 0) {
      b = n / a;
      if (a * b == n && cnt > (a + b - 2)) cnt = a + b - 2;
    }

  cout << cnt << endl;
}