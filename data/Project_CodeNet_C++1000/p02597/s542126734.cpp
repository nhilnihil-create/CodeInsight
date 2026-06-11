#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n;
  cin >> n;
  char c[n];
  rep(i,n) cin >> c[i];
  
  int s = 0, r = 0;
  rep(i,n) if(c[i] == 'R') s += 1;
  rep(i,s) if(c[i] == 'R') r += 1;
  cout << s - r << endl;
  return 0;
}