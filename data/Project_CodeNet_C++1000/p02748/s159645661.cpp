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
using namespace std;

int inf = 2147483647;
int64_t inf64 = 9223372036854775807;
int mod = 1e+7;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  int mina = inf;
  int minb = inf;
  rep(i,A) {cin >> a[i]; mina = min(mina, a[i]);}
  rep(i,B) {cin >> b[i]; minb = min(minb, b[i]);}

  int res = mina + minb;
  rep(i,M) {
    int x, y, c;
    cin >> x >> y >> c;
    x--; y--;
    res = min(res, a[x]+b[y]-c);
  }
  cout << res << endl;
  return 0;
}