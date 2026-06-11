#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v = {a,b};
  if(a==1 && b==1) cout << 1000000 << endl;
  else {
    int ans = 0;
    for(int i=0; i<2; i++) {
      if(v[i]==1) ans += 300000;
      if(v[i]==2) ans += 200000;
      if(v[i]==3) ans += 100000;
    }
  cout << ans << endl;
  }
  return 0;
}