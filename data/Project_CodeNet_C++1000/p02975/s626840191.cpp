#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

  bool ok = false;
  if (n % 3 != 0) {
    if (mp.size() == 1 && mp[0] > 0) {
      ok = true;  // 000000000...
    }
  } else {
    if (mp.size() == 3) {
      auto itr = mp.begin();
      auto itr2 = itr;
      if ((*itr).second == n / 3 && (*(++itr)).second == n / 3 &&
          (*(++itr)).second == n / 3) {
        if (((*itr2).first ^ (*(++itr2)).first ^ (*(++itr2)).first) == 0) {
          ok = true;  // xyz xyz xyz xyz
        }
      }
    } else if (mp.size() == 2) {
      if (mp[0] == n / 3) {
        ok = true;  // 0xx 0xx 0xx 0xx
      }
    } else if (mp.size() == 1) {
      if (mp[0] > 0) {
        ok = true;  // 000000000
      }
    }
  }

  if (ok) {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}
