#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n;
  cin >> n;
  
  int s = 0;
  rep(i,n) {
    int j = i + 1;
    s += j * (n/j) * (n/j + 1) / 2;
  }
  cout << s << endl;
  return 0;
}