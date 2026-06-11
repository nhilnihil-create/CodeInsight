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

int main() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  vector<int> v(n);
  REP(i, n) {
    cin >> v[i];
    count += v[i];
  }
  sort(v.begin(), v.end(), greater<int>());
  REP(i, m) {
    if(v[i] < ((double)count / (4 * m))) {
        cout << "No" << endl;
        return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
