/**
*    author:  Dooloper
*    created: 03.09.2020 19:36:23
**/
#include <bits/stdc++.h>
using namespace std;

#define A 1000006

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(A);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c[a[i]]++;
  }

  bool pairwise = true;
  for (int i = 2; i < A; ++i) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += c[j];
    }
    if (cnt > 1) {
      pairwise = false;
      break;
    }
  }

  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = 0;
  for (int i = 0; i < n; ++i) {
    g = gcd(g, a[i]);
    if (g == 1) {
      cout << "setwise coprime" << endl;
      return 0;
    }
  }

  cout << "not coprime" << endl;

  return 0;
}