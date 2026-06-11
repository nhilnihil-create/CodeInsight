#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int h1, m1, h2, m2, k; cin >> h1 >> m1 >> h2 >> m2 >> k;
  int s = h1 * 60 + m1;
  int e = h2 * 60 + m2;
  cout << max(e - s - k, 0) << endl;

  return 0;
}

// EOF