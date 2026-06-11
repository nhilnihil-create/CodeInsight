#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int mod = (int)1e9+7;

signed main() {
  int n, k;
  cin >> n >> k;
  
  int s = 0;
  rep(i,n+2-k) {
    int j = k + i;
    s += j * (n - j + 1) + 1;
    s %= mod;
  }
  cout << s << endl;
  return 0; 
}