#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define EPS 1e-10
#define INF 1000000000
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long ll;

int calcATP(int p, int vat) {
  return (int)(p * (100 + vat) / 100);
}

int main() {
  while (1) {
    int x, y, s, ans = 0;
    cin >> x >> y >> s;
    if (!x && !y && !s) {
      break;
    }
    for (int i = 1; i < s; i++) {
      int p0 = calcATP(i, x);
      for (int j = s - p0; j > 0 && i <= j; j--) {
        int p1 = calcATP(j, x);
        if (p0 + p1 == s) {
          int p = calcATP(i, y) + calcATP(j, y);
          ans = max(ans, p);
        } else if (p0 + p1 < s) {
          break;
        }
      }
    }
    cout << ans << endl;
  }
}