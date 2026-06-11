
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  int x;
  scanf("%d", &x);
  int res = 0;
  res += x / 500 * 1000;
  x -= x / 500 * 500;
  res += x / 5 * 5;
  cout << res << endl;
  
  return 0;
}
