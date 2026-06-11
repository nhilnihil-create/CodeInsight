#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a,b,k;
  cin >> a >> b >> k;
  if(k > a) {
    k -= a;
    a = 0;
  } else {
    a -= k;
    cout << a << " " << b << endl;
    return 0;
  }
  if(k > b) {
    cout << a << " " << 0 << endl;
    return 0;
  } else {
    cout << a << " " << b-k << endl;
  }
}