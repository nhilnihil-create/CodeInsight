
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  ll n;
  scanf("%lld", &n);
  ll res = 0;
  for(ll i = 2; i <= 1000000; ++i) {
    int cnt = 0;
    while(n % i == 0) {
      n /= i;
      ++cnt;
    }
    int cur = 1;
    while(cnt >= cur) {
      cnt -= cur;
      ++cur;
    }
    res += cur-1;
  }
  if(n > 1) {
    ++res;
  }
  cout << res << endl;
  return 0;
}
