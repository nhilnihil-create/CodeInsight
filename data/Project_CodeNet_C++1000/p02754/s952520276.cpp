
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  ll N, A, B;
  cin >> N >> A >> B;
  ll res = 0;
  res += N / (A+B) * A;
  ll r = N % (A+B);
  res += min(A, r);
  cout << res << endl;
  return 0;
}
