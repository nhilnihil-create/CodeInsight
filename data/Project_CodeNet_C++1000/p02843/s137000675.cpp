#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll X;
  cin >> X;
  ll P = X / 100;
  ll Q = X % 100;
  if(P >= (Q + 4) / 5) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}