#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;
int a, b;

void solve() {
  cin >> a >> b;
  if (2*b>=a) {
    cout<< "0\n";
  } else {
    cout << (a-2*b) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
