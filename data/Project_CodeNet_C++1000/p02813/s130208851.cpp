#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a = 10, b = 10, loop = 0;
  cin >> n;
  vector<int> v(n), p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    v[i] = i + 1;
  }
  for (int i = 0; i < n; i++) cin >> q[i];
  do {
    bool flag_p = true, flag_q = true;
    if(a == 10) {
      for(int i = 0; i < n; i++) {
        if(v[i] != p[i]) {
          flag_p = false;
          break;
        }
      }
      if(flag_p) a = loop;
    }
    if(b == 10) {
      for(int i = 0; i < n; i++) {
        if(v[i] != q[i]) {
          flag_q = false;
          break;
        }
      }
      if(flag_q) b = loop;
    }
    if(a != 10 && b != 10) break;
    loop++;
  } while (next_permutation(v.begin(), v.end()));
  cout << abs(a-b);
}