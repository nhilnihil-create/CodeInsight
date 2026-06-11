#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milkshake() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      for(int k = 0; k < 10; k++) {
        string t;
        t.push_back('0' + i);
        t.push_back('0' + j);
        t.push_back('0' + k);

        int l = 0, m = 0;
        while(l + m < n) {
          if(t[m] == s[l + m]) m++;
          else l++;
          if(m < 3) continue;
          ans++;
          break;
        }
      }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) milkshake();

  return 0;
}

