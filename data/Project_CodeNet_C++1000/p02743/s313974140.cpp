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
  ll a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);

  long double ra = sqrtl(a);
  long double rb = sqrtl(b);
  // long double rc = sqrtl(c);

  if (c > a + b + 2 * ra * rb) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
