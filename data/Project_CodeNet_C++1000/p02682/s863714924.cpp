#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  scanf("%d %d %d %d", &a, &b, &c, &k);
  if(a >= k) cout << k;
  else if(a + b >= k) cout << a;
  else cout << (2*a + b - k);
}