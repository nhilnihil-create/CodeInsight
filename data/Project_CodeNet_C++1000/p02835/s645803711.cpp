#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("data.in", "r", stdin);
  int a, b, c;
  cin >> a >> b >> c;
  puts(a+b+c >= 22 ? "bust" : "win");
  return 0;
}