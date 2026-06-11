#include <bits/stdc++.h>
using namespace std;

int vals[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  vals[a] = 1;
  vals[b] = 1;
  vals[c] = 1;
  int ans = 0;
  for (int i = 0; i < 10; i++) ans += vals[i];
  cout << (ans == 2?"Yes\n":"No\n");
  return 0;
} 