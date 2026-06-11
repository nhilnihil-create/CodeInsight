#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  ll money = 1000, stock = 0;
  for (int i = 1; i < n; i++) {
    if (a.at(i - 1) < a.at(i)) {
      money += (a.at(i) - a.at(i - 1)) * (money / a.at(i - 1));
    }
  }
  
  cout << money << '\n';
}