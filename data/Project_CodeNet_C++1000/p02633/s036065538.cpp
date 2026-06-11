#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int x; cin >> x;
  for(int k=1; ; k++) {
    if ((k * x)%360 == 0) {
      cout << k << endl;
      return 0;
    }
  }

  return 0;
}

// EOF