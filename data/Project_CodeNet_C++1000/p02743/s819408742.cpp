#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  long long a, b, c; cin >> a >> b >> c;
  if ( c - a - b > 0 && 4*a*b < (c-a-b)*(c-a-b)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

// EOF