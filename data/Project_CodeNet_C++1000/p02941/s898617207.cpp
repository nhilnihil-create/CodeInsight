#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  int n; cin >> n;
  vector<lint> a(n);
  vector<lint> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  priority_queue<pair<lint, lint>> pq;

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] > a[i]) {
      pq.push({b[i], i});
    }
  }

  lint ans = 0;
  while (!pq.empty()) {
    lint val;
    lint i;
    tie(val, i) = pq.top();
    pq.pop();

    if (b[i] > a[i]) {
      int tmp = ans;
      ans += (b[i] - a[i]) / (b[(i - 1 + n) % n] + b[(i + 1) % n]);
      if (ans == tmp) break;
      b[i] = (b[i] - a[i]) % (b[(i - 1 + n) % n] + b[(i + 1) % n]) + a[i];
      pq.push({b[i], i});
    }

  }

  for (int i = 0; i < n; i++) {
    if (b[i] != a[i]) {
      ans = -1;
    }
  }

  cout << ans << endl;
  return 0;
}
