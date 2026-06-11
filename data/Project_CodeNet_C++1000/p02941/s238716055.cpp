#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<ll> dqll;

#define MOD 1000000007

int main() {
  ll N;

  cin >> N;

  vll goal(N);
  vll cur(N);
  for (int i = 0; i < N; i++) {
    cin >> goal[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> cur[i];
  }

  queue<ll> que;
  for (int i = 0; i < N; i++) {
    ll idx1 = (i - 1 + N) % N;
    ll idx2 = (i + 1) % N;
    if (cur[i] > cur[idx1] + cur[idx2]) {
      que.push(i);
    }
  }  // i

  ll ans = 0;
  bool flag = false;
  while (!que.empty()) {
    ll tmp = que.front();
    que.pop();

    ll idx1 = (tmp - 1 + N) % N;
    ll idx2 = (tmp + 1) % N;

    ll tryval = cur[tmp] % (cur[idx1] + cur[idx2]);
    if (tryval < goal[tmp]) {
      ll checkval = cur[tmp] - goal[tmp];
      if (checkval % (cur[idx1] + cur[idx2]) != 0) {
        break;
      }
      cur[tmp] = goal[tmp];
      ans += checkval / (cur[idx1] + cur[idx2]);
    } else {
      ans += (cur[tmp] / (cur[idx1] + cur[idx2]));
      cur[tmp] %= (cur[idx1] + cur[idx2]);
    }

    ll idx1p = (tmp - 2 + N) % N;
    ll idx2p = (tmp + 2) % N;
    if (cur[idx1] > cur[idx1p] + cur[tmp]) que.push(idx1);
    if (cur[idx2] > cur[idx2p] + cur[tmp]) que.push(idx2);
  }  // while

  flag = true;
  for (int i = 0; i < N; i++) {
    if (goal[i] != cur[i]) {
      flag = false;
      break;
    }
  } // i

  if (!flag) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
