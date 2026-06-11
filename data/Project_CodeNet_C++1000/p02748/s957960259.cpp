#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> ref(a), ran(b);
  for (int i=0; i<a; ++i) cin >> ref.at(i);
  for (int i=0; i<b; ++i) cin >> ran.at(i);
  int min_ref = 1e9, min_ran = 1e9;
  for (int i=0; i<a; ++i) if (ref.at(i) < min_ref) min_ref = ref.at(i);
  for (int i=0; i<b; ++i) if (ran.at(i) < min_ran) min_ran = ran.at(i);
  
  int res = min_ref + min_ran;
  for (int i=0; i<m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    int tmp = ref.at(x-1) + ran.at(y-1) - c;
    if (tmp < res) res = tmp;
  }
  
  cout << res << endl;
  return 0;
}
