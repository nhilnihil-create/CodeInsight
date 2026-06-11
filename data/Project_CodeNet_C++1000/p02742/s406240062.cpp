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
  ll H, W;
  scanf("%lld %lld", &H, &W);

  ll num1 = (W % 2 == 1) ? W / 2 + 1 : W / 2;
  ll num2 = W / 2;

  ll count1 = (H % 2 == 1) ? H / 2 + 1 : H / 2;
  ll count2 = H / 2;

  if (H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll a = num1 * count1 + num2 * count2;
  cout << a << endl;
}
