#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll X;
  scanf("%lld", &X);

  ll r = 0;
  for (ll i = 0; i <= 1000; i++) {
    if (X >= 100 * i && X <= 105 * i) {
      r = 1;
    }
  }

  cout << r << endl;
}
