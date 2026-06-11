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
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<int> dp(n, 0);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (h[i] <= h[i - 1]) {
      dp[i] = dp[i - 1] + 1;
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
