#include <bits/stdc++.h>

using namespace std;

#define ll long long

int a, b;

void solve() {
  cin >> a >> b;
  if ((a>9)||(b>9)) {
    cout << "-1\n";
  } else {
    cout << a*b << '\n';
  }
}   

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
