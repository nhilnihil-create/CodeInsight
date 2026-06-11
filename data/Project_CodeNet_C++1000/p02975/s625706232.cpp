#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mp[a]++;
  }

  if (mp.size() == 1) {
    if (mp[0] == n) puts("Yes");
    else puts("No");
  } else if (mp.size() == 2) {
    if (n % 3 != 0) {
      puts("No");
    } else {
      int a = n / 3;
      if (mp[0] == a) puts("Yes");
      else puts("No");
    }
  } else if (mp.size() == 3) {
    if (n % 3 != 0) {
      puts("No");
    } else {
      int a = n / 3;
      bool ok = true;
      int xo = -1;
      for (auto e: mp) {
	if (xo == -1) xo = e.first;
	else xo = xo ^ e.first;
	if (e.second != a) {
	  ok = false;
	  break;
	}
      }
      if (ok && xo == 0) puts("Yes");
      else puts("No");
    }
  } else {
    puts("No");
  }
  return 0;
}
