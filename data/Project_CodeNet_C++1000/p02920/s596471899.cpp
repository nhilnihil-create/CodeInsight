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
typedef deque<ll> dqll;

#define MOD 1000000007

int main() {
  ll N;

  cin >> N;

  ll Nslm = 1LL << N;

  vll slmLst(Nslm, 0);
  for (int i = 0; i < Nslm; i++) {
    cin >> slmLst[i];
  }

  sort(slmLst.begin(), slmLst.end());
  reverse(slmLst.begin(), slmLst.end());

  dqll curgen(1, slmLst[0]);
  slmLst[0] = -1;
  for (int i = 0; i < N; i++) {
    dqll pregen = curgen;
    sort(pregen.begin(), pregen.end());
    reverse(pregen.begin(), pregen.end());
    int j = 0;
    while (pregen.size() > 0 && j < Nslm) {
      if (slmLst[j] == -1) {
      } else if (pregen[0] > slmLst[j]) {
        pregen.pop_front();
        curgen.push_back(slmLst[j]);
        slmLst[j] = -1;
      }
      j++;
    }
    if (pregen.size() > 0) {
      puts("No");
      return 0;
    }
  }  // i

  puts("Yes");

  return 0;
}
