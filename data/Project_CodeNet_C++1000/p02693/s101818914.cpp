#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  scanf("%d\n%d %d", &k, &a, &b);
  if((b - a) >= k || a % k > b % k || a % k == 0) cout << "OK";
  else cout << "NG";
}