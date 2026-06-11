#include <iostream>
using namespace std;

int main(){
  int n, x, t, ans = 0;
  cin >> n >> x >> t;
  while(n > 0){
    n -= x;
    ans += t;
  }
  cout << ans << endl;
  return 0;
}