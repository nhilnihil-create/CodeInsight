#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int a, b, ans;
  cin >> a >> b;
  if (a < 10 && b < 10)
    ans = a * b;
  else
    ans = -1;
  cout << ans << endl;
  return 0;
}