#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t p,v,p1,v1,p2,v2,t;
  cin >> p1 >> v1 >> p2 >> v2 >> t;
  p=abs(p2-p1);
  if(v1<=v2) {
    cout << "NO" << endl;
    return 0;
  }
  v=v1-v2;
  if ( p<=v*t ) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}
