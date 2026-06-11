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

  int ans[32] =  {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

  int k;

  cin >> k;

  cout << ans[--k];

  return 0;
}
/*

*/
