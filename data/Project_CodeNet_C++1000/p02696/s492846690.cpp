#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll A, B, n;
  cin >> A >> B >> n;
  ll r = min(B - 1, n);
  cout << (ll)A * r / B << endl;
  return 0;
}
