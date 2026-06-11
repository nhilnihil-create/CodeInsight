#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ma = 0;
  bool res = true;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (ma - a >= 2) res = false;
    ma = max(ma, a);
  }
  if (res) puts("Yes");
  else puts("No");
}