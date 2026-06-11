#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int all = 0;
  rep(i,n) all ^= a[i];
  rep(i,n-1) cout << (all ^ a[i]) << " ";
  cout << (all ^ a.back()) << endl;
}