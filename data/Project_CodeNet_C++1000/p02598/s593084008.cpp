#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int A[200000];
    int i, j;
    int N, K;

int main() {
  cin >> N >> K;
  rep0(i, N) cin >> A[i];
 
  int ng = 0, ok = 1e9 + 1;
  while (ok - ng > 1) {
    int m = (ok + ng) / 2;
    int cnt = 0;
    rep0(i, N) { cnt += (A[i] - 1) / m ; }
    if (cnt <= K)
      ok = m;
    else
      ng = m;
  }
  cout << ok << endl;
  return 0;
}