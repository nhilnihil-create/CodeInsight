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
  ll h1, m1, h2, m2, k;
  scanf("%lld %lld %lld %lld %lld", &h1, &m1, &h2, &m2, &k);

  ll t1 = h1 * 60 + m1;
  ll t2 = h2 * 60 + m2;

  ll o = t2 - t1;
  ll a = (o - k);

  if (a < 0) {
    a = 0;
  }

  cout << a << endl;
}
