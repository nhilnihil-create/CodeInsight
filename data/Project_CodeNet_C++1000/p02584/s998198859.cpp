#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll X, K, D;
  cin >> X >> K >> D;
  X = abs(X);
  ll k = min(K, X/D);
  X -= k*D;
  K -= k;
  if (K & 1) X = D-X;
  cout << X << endl;
}