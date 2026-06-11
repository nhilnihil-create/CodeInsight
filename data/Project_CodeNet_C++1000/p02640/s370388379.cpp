
#include <cstdio>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int x, y;
  cin >> x >> y;
  REP(i, x+1) {
    if(i*2 + (x-i)*4 == y) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
