
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

int main(void) {
  ll a, b, n;
  cin >> a >> b >> n;
  ll x = min(b-1, n);
  cout << a*x/b - a * (x/b) << endl;
  return 0;
}
