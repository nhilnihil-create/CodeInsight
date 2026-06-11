#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  
  int all_aji = 0;
  for (int i = 0; i < n; i++) all_aji += l+i;
  int d = 101;
  for (int i = 0; i < n; i++) d = min(d, abs(l+i));
  if (all_aji < 0) cout << all_aji+d << endl;
  else cout << all_aji-d << endl;
}