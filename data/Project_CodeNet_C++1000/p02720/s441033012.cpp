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
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k;
  cin >> k;

  queue<int64_t> lunluns;
  rep(i,9) lunluns.push(i+1);
  rep(i,k-1) {
    int64_t x = lunluns.front();
    lunluns.pop();

    int64_t n = x * 10 + x % 10;
    if (x % 10 != 0) lunluns.push(n-1);
    lunluns.push(n);
    if (x % 10 != 9) lunluns.push(n+1);
  }

  cout << lunluns.front() << endl;
  return 0;
}