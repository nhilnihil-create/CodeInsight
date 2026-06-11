#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
//__int128


signed main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(10);
  int n, k;
  cin >> n >> k;
  vi a(n);
  int tot = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    tot += a[i];
  }
  int res = 1;
  vi t(n);
  for(int i = 1; i * i <= tot; ++i) {
    if(tot % i) continue;
    auto run = [&](int d) {
      int r = 0;
      for(int j = 0; j < n; ++j) {
        t[j] = a[j] % d;
        r += t[j];
      }
      int m = r / d;
      sort(all(t));
      int tt = 0;
      for(int j = 0; j < n - m; ++j) {
        tt += t[j];
      }
      if(tt <= k) {
        res = max(res, d);
      }
    };
    run(i);
    run(tot / i);
  }
  cout << res << endl;
  return 0;
}