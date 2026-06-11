/**
 *    author:  morato
 *    created: 29.08.2020 17:11:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  bool flag = false;
  for (int i = 0; i <= x; i++) {
    int dois = i * 2;
    int quatro = (x - i) * 4;
    if (dois + quatro == y) {
      flag = true;
    }
  }
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}