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
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  ll sum1 = 0;
  ll sum2 = 0;

  for (ll i = 1; i <= N; i++) {
    sum1 += (i * (N - i + 1));
  }

  for (ll i = 1; i <= N - 1; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    if (a > b) swap(a, b);
    sum2 += ((a) * (N - b + 1));
  }

  cout << sum1 - sum2 << endl;
}
