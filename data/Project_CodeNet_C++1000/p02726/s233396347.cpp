#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--; y--;
  
  int r[n];
  rep(i,n) r[i] = 0;
  rep(i,n) rep(j0,n-i-1) {
    int j = j0 + i + 1;
    int k = min(j - i, abs(x - i) + 1 + abs(y - j));
    r[k]++;
  }
  rep(i,n-1) cout << r[i+1] << endl;
  return 0;
}