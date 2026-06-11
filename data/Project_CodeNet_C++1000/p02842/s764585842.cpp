#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double n;
  cin >> n;
  double x;
  x = n/1.08;
  double xx = ceil(x);
  double k = 1/1.08;
  if (xx >= x + k) cout << " :(" ;
  else cout << xx;
}

