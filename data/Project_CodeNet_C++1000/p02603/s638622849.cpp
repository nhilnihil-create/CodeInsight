#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  ll cur = 1000;
  for (int i = 1; i < n; i++) if (a[i] > a[i - 1]) {
    ll cnt = cur / a[i - 1];
    cur -= cnt * a[i - 1];
    cur += cnt * a[i];
  }
  cout << cur << '\n';
  return 0;
}