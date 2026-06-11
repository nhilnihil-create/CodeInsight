#include "bits/stdc++.h"
#define F first
#define S second
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n = 0, r = 0;
  cin >> n >> r;
  if (n >= 10) cout << r;
  else {
    cout << r + (10 - n) * 100;
  }
}
