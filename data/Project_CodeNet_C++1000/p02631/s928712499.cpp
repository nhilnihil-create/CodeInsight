#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int x = 0;
  rep(i,n) x ^= a[i];
  rep(i,n) cout << (x ^ a[i]) << endl;
}