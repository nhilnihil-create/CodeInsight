#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <stack>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repl(i, n) for(LL i = 0; i < (LL)(n); i++)

LL modpow(LL a, LL n) {
  LL result = 1;
  if (n == 0) {
    return 1;
  } else {
    for (int i = 0; i < n; i++) {
      result = (result * a) % 998244353;
    }
  }

  return result;
}

int main(void){
  int n;
  cin >> n;

  vector<int> distance(100000);
  int d;
  int dmax = 0;

  rep(i, n) {
    cin >> d;
    if ((i == 0 && d != 0) || (i != 0 && d == 0)) {
      cout << 0 << endl;
      return 0;
    }
    dmax = max(d, dmax);
    distance[d] ++;
  }

  LL ans = 1;
  for (int i = 1; i < dmax; i++) {
    LL sets = modpow(distance[i], distance[i+1]);
    ans = (ans * sets) % 998244353;
  }

  cout << ans << endl;

  return 0;
}