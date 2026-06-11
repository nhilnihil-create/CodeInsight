
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  ll a, b, c;
  scanf("%lld %lld.%lld", &a, &b, &c);
  ll r = a * (b*100+c) / 100;
  cout << r << endl;
  return 0;
}
