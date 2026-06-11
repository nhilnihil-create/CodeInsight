#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int mx = n - k + 1;
  int mn = k == 1 ? mx : 1;
  cout << mx - mn << endl;
}