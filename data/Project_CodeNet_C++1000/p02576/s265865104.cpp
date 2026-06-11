#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n, x, t; cin >> n >> x >> t;
  cout << ((n+x-1) / x) * t << endl;

  return 0;
}

// EOF