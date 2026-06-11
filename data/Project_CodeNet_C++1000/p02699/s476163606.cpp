#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;


int main() {
  int s, w;
  cin >> s >> w;
  string ans = "safe";
  if(s <= w) ans = "unsafe";
  
  cout << ans << endl;
  return 0;
}
