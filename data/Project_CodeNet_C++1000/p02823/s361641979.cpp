#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  long long n; cin >> n;
  long long a, b; cin >> a >> b;
  if ((b-a)%2 == 0) {
    cout << (b-a)/2 << endl;
  } else {
    cout << min(a+b-1, 2*n-b-a+1)/2 << endl;
  }

  return 0;
}

// EOF
