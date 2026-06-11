#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, s, c;
  bool a = true;
  cin >> n >> m;
  vector<int> v(4, -1);
  for(int i = 0;i < m;i++) {
    cin >> s >> c;
    if(v[s] == -1 || v[s] == c) v[s] = c;
    else a = false;
  }
  if(n != 1 && v[1] == 0) a = false;
  if(a) {
    if(n == 1) cout << ((v[1] == -1) ? 0 : v[1]) << endl;
    else {
      if(v[1] == -1) v[1] = 1;
      if(v[2] == -1) v[2] = 0;
      if(v[3] == -1) v[3] = 0;
      for(int i = 1;i <= n;i++) cout << v[i];
      cout << endl;
    }
  } else cout << -1 << endl;
}