#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int k;
  cin >> k;
  bool isExist = false;
  int now = 0;
  int result = 0;
  rep (i, k) {
    now = (now * 10 + 7) % k;
    if (now == 0) {
      isExist = true;
      result = i+1;
      break;
    }
  }

  if (isExist) {
    cout << result << endl;
  } else {
    cout << -1 << endl;
  }
}
