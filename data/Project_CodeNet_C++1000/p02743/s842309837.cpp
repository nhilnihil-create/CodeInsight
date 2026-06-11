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

  ll a, b, c;

  cin >> a >> b >> c;

  ll d = c - a - b;

  if(d > 0 && d * d > 4 * a * b) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
/*

*/
