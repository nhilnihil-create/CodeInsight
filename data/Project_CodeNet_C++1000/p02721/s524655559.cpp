#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <random>
#define REP(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

ll n, k, c, l[200010], r[200010];
string s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k >> c >> s;

  for(int i = 0; i < n; ++i) {
    if (s[i] == 'o') {
      l[i + 1]++;
      i += c;
    }
  }
  for(int i = n - 1; i >= 0; --i) {
    if (s[i] == 'o') {
      r[i]++;
      i -= c;
    }
  }
  REP(i, n) l[i + 1] += l[i];
  for(int i = n; i >= 1; --i) r[i - 1] += r[i];
  
  // check: 
  for(int i = 0; i < n; ++i) {
    if(l[i] + r[i + 1] < k) {
      cout << i + 1 << '\n';
    }
  }
  return 0;
}

