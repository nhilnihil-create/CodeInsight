
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void) {
  int k, a, b;
  cin >> k >> a >> b;
  for(int i = a; i <= b; ++i) {
    if(i % k == 0) {
      puts("OK");
      return 0;
    }
  }
  puts("NG");
  return 0;
}
