#include "bits/stdc++.h"
#define F first
#define S second
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
ll fun(ll x) {
  if (x > 1)
    return 2 * fun(x / 2) + 1;
  else
    return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll h = 0;
  cin >> h;
  cout << fun(h);
}

