#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int d = a*b;
  int ans = 0;
  while(true) {
    if(d-a*b>=c) break;
    if(a<=b) a--;
    else b--;
    ans++;
  }
  cout << ans << endl;
  return 0;
}