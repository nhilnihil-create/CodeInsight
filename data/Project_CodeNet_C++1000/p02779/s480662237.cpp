#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  set<int> S;
  bool c = 0;
  for(int i : a) {
    if(S.count(i)) {
      c = 1;
      break;
    }
    else S.insert(i);
  }
  if(c) cout << "NO" << endl;
  else cout << "YES" << endl;
}