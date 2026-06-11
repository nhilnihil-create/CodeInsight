#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ll X, K, D, Kmin, dx1, dx2, ans;
  cin >> X >> K >> D;
  X = abs(X);
  Kmin = X / D;
  if (K <= Kmin) {
    cout << X - D*K << endl;
    return 0;
  }
  dx1 = X%D;
  dx2 = D - dx1;
  if ((K - Kmin)%2 == 0) {
    cout << dx1 << endl;
  } else {
    cout << dx2 << endl;
  }
  return 0;
}