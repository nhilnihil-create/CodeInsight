#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, k, c[3];
  cin >> n >> k;
  rep(i,3) cin >> c[i];
  int s[n];
  rep(i,n) {
    char t;
    cin >> t;
    s[i] = (t == 'r' ? 2 : (t == 's' ? 0 : 1));
  }
  
  int r = 0;
  rep(i,n) r += c[s[i]];
  
  rep(i,k) {
    int p = s[i], m = 1;
    rep(j,n) {
      if(i+k*(j+1) < n && s[i+k*(j+1)] == p) m += 1;
      else {
        r -= c[p] * (m / 2);
        if(i+k*(j+1) >= n) break;
        p = s[i+k*(j+1)];
        m = 1;
      }
    }
  }
  
  cout << r << endl;
  return 0;
}