#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#include <bit>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s;

  cin >> s;

  ll cur = 0;

  ll a[2019] = {0};

  a[0] = 1;

  ll ans = 0;

  ll n = s.size();

  for(ll i = 0; i < n; i++) {
    cur = (cur * 10 + (s[i] - '0')) % 2019;
    ans += a[cur];
    a[cur]++;
    ll b[2019] = {0};
    for(ll j = 0; j < 2019; j++)
      b[j * 10 % 2019] = a[j];
    for(ll j = 0; j < 2019; j++)
      a[j] = b[j];
  }

  cout << ans;

  return 0;
}
/*

*/
