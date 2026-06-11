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
  ll A, V;
  scanf("%lld %lld", &A, &V);

  ll B, W;
  scanf("%lld %lld", &B, &W);

  ll T;
  scanf("%lld", &T);

  ll o = abs(A - B);
  ll d = (V - W) * T;

  if (o <= d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
