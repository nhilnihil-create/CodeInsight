#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, num, cnt = 0;
  vector<int> a;
  bool pos[110] = {0};
  cin >> x >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    pos[num] = 1;
  }
  for (int i = 0; i <= 105; i++) {
    if (pos[i] == 0) a.push_back(i);
  }
  int ans = upper_bound(a.begin(), a.end(), x) - a.begin();
  if (a[ans] - x >= x - a[ans - 1]) {
    ans--;
  }
  printf("%d\n", a[ans]);
  return 0;
}
