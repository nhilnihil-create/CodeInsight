#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (a1 > b1) {
    swap(a1, b1);
    swap(a2, b2);
  }
  ll p = (a1-b1)*t1;
  ll q = (a2-b2)*t2;
  if (p+q < 0) {
    cout << 0 << endl;
    return 0;
  }
  if (p+q == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  if ((-p)%(p+q) != 0) {
    cout << ((-p)/(p+q))*2 + 1 << endl;
  }
  else {
    cout << ((-p)/(p+q))*2 << endl;
  }
}