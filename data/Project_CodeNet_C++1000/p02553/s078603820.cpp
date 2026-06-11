#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll cnt[1000010];
int main() {
  ll a, b, c, d; cin >> a >> b >> c >> d;
  cout << max({a * c, a * d, b * c, b * d}) << endl;
}