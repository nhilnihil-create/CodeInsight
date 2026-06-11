#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int a, b, c, k; cin >> a >> b >> c >> k;
  for(int i=0; i<k; i++) {
    if (a >= b) b *= 2;
    else if (b >= c) c *= 2;
  }

  if (a < b && b < c) {
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}

// EOF