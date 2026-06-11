#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <regex>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,j,n) for(int i = j; i < n; i++)
#define rrep(i,j,n) for(int i = j-1; i >= n; i--)
#define prec(n) fixed << setprecision(n)
#define print_array(v) rep(__k, v.size()) { cout << v[__k]; if(__k != v.size()-1) cout << " "; else cout << endl; }
#define YesorNo(a) printf(a?"Yes\n":"No\n")
#define fi first
#define se second
#define endl "\n"
using namespace std;

//constexpr int inf = 2147483647;
//constexpr int64_t inf64 = 9223372036854775807;
//constexpr int mod = 1e9+7;

int64_t f(int64_t n) {
  return n*(n-1)/2;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int64_t> a(n);
  rep(i,n) cin >> a[i], a[i]--;

  vector<int64_t> cnt(n, 0);
  rep(i,n) cnt[a[i]]++;

  int64_t all = 0;
  rep(i,n) all += f(cnt[i]);

  rep(i,n) {
    cout << all - f(cnt[a[i]]) + f(cnt[a[i]]-1) << endl;
  }

  return 0;
}