#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int f(int n, int d) {
  return n / d;
}

int main() {
  int l, r, d; cin >> l >> r >> d;
  cout << f(r, d) - f(l-1, d) << endl;
  return 0;
}

// EOF