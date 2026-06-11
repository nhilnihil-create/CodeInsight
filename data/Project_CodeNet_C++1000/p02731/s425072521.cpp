#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int l;

  cin >> l;

  double hen;

  hen = double(l/3);

  double hen2 = hen*hen*hen;

  cout << fixed << setprecision(10) << (double)(l*l*l)/27;

}