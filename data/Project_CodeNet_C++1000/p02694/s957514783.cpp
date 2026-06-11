
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

int main(void) {
  ll x;
  cin >> x;
  ll cur = 100;
  for(int i = 1; ; ++i) {
    cur += cur / 100;
    if(cur >= x) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
