#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> buka(n, 0);
  for (int i = 1; i < n; ++i) buka[a[i]]++;
  rep(i, n) cout << buka[i] << endl;
  return 0;
}