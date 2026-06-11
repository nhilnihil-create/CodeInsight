#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  vector<int> a(3);
  rep(i,3) cin >> a[i];
  sort(rng(a));
  cout << a[0] + a[1] << endl;
  return 0;
}