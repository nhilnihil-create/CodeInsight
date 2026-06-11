#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int solve(int h) {
  if(h <= 1) return 1;
  else return 1 + 2 * solve(h / 2);
}

signed main() {
  int h;
  cin >> h;
  cout << solve(h) << endl;
  return 0;
}