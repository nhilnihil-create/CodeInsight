#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int p, q, r;
  cin >> p >> q >> r;
  int m = max(max(p, q), r);
  int ans = p + q + r - m;
  cout << ans << endl;
  
  return 0;
}