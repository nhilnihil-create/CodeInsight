#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int r_count = 0, l_count = 0, r = 0, l = 1;
  vector<int> v(n);
  rep(i, n) {
    if (s[i] == 'R') r_count++;
    if (s[i] == 'L') l_count++;
    if (s[i] == 'R' && s[i + 1] == 'L') r = i, l = i + 1;
    if (s[i] == 'L' && s[i + 1] == 'R' || i == n - 1) {
      int count = r_count + l_count;
      v[r] = count / 2, v[l] = count / 2;
      if (count % 2 != 0) {
        if ((max(r_count, l_count) - 1) % 2 == 0) {
          if (r_count > l_count)
            v[r]++;
          else
            v[l]++;
        } else {
          if (r_count > l_count)
            v[l]++;
          else
            v[r]++;
        }
      }
      r_count = 0, l_count = 0;
    }
  }
  for (auto m : v) cout << m << " ";
  cout << endl;
  return 0;
}