#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  unordered_set<int> prev;
  int ans = n;
  for(int i = 0; i < n; ++i) {
    bool ettara7et = false;
    for(int j = 1; j * j <= a[i]; ++j) {
      if(a[i] % j == 0) {
        if(prev.count(j)) {
          ans--;
          ettara7et = true;
          break;
        }
        if(prev.count(a[i] / j)) {
          ans--;
          ettara7et = true;
          break;
        }
      }
    }
    if(!ettara7et && i + 1 < n && a[i + 1] == a[i]) {
      ans--;
    }
    prev.insert(a[i]);
  }
  cout << ans << endl;
  return 0;
}
