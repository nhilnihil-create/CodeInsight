#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <functional>
#include <utility>
#include <iterator>

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (m); i < (int)(n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

//const double PI = 3.1415926535897932384626433832795;

int main() {
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  if(s != r) {
    cout << "No" << endl;
    return 0;
  }
  int sublen = (s.size() - 1) / 2;
  string sub = s.substr(0, sublen);
  string subr = sub;
  reverse(subr.begin(), subr.end());
  if(sub != subr) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
