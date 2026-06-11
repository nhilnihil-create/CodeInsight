#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {

  int x, n, p;
  int a[102] = {0};
  int res = 1000;   //適当な大きい初期値
  int ans = 0;      //適当な初期値
  cin >> x >> n;
  for(int i=0; i<n; ++i) {
    cin >> p;
    a[p] = 1;
  }

  /*res = x-0;  //最小のものが正に無いときは0が最小である
  ans = 0;
  res = min(res, abs(101-x)); //最小のものが100までにないときは101が最小である
  if(res!=x-0) ans = 101;

  for(int i=1; i<=100; ++i) {
    if(a[i]==0) {
      if(res>abs(i-x)) {
        res = abs(i-x);
        ans = i;
      }
    }
  }*/

  for(int i=0; i<=101; ++i) {
    if(a[i]==0) {
      if(res>abs(i-x)) {
        res = abs(i-x);
        ans = i;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
