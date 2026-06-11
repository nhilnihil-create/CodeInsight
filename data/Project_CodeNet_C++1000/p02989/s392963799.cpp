#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int n; cin >> n;
  std::vector<int> d(n);
  rep(i,n) cin >> d.at(i);
  sort(d.begin(), d.end());
  cout << d.at(n/2) - d.at(n/2-1) << endl;
}
