//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  bool flag = true;
  if (c <= a+b) flag = false;
  if (4*a*b >= (c-a-b) * (c-a-b)) flag = false;
  
  if (flag) puts("Yes");
  else puts("No");
  return 0;
}