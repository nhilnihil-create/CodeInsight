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
  ll N, K, S;
  scanf("%lld %lld %lld", &N, &K, &S);

  ll val = S;
  for (ll i = 0; i < K; i++) {
    cout << val << " ";
  }

  if (S == 1000000000LL) {
    val--;
  } else {
    val++;
  }

  for (ll i = 0; i < (N - K); i++) {
    cout << val << " ";
  }
  cout << "" << endl;
}
