#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll X;
  cin >> X;

  vector<ll> list(1, 0);
  ll a = 1;
  ll r;
  vector<ll>::iterator itr;
  while (true) {
    ll a5 = pow(a, 5);
    list.push_back(a5);
    ll p = X / a5;
    if (p > 1) {
      a++;
      continue;
    }

    if (p == 1) {
      r = X % a5;
    }
    if (p == 0) {
      r = X % a5 - a5;
      // break;
    }
    itr = find(list.begin(), list.end(), abs(r));
    if (itr != list.end()) break;
    a++;
  }

  auto index = distance(list.begin(), itr);  // absolutely exists
  auto b = r > 0 ? -index : index;
  cout << a << " " << b << endl;
}
