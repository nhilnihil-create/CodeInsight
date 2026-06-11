#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define all(v) begin(v), end(v)

typedef long long Long;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  if (cnt.size() > 3) {
    cout << "No" << endl;
    return 0;
  }
  if (cnt.size() == 1) {
    if (cnt.begin()->first != 0) {
      cout << "No" << endl;
      return 0;
    } else {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (cnt.size() == 2) {
    if (cnt.begin()->first != 0 || n % 3 != 0 ||
        cnt.rbegin()->second != 2 * cnt.begin()->second) {
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    return 0;
  }
  if (cnt.size() == 3) {
    auto it1 = cnt.begin();
    auto it2 = it1;
    ++it2;
    auto it3 = it2;
    ++it3;
    if ((it1->first ^ it2->first) == it3->first && it1->second == it2->second &&
        it2->second == it3->second) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  return 0;
}
