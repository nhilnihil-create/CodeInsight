
#include <cstdio>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int s = 0;
  REP(i, 5) {
    int v;
    cin >> v;
    s += v;
  }
  cout << 15 - s << endl;

  return 0;
}
