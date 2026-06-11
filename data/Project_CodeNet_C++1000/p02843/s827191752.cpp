
#include <cstdio>
#include <iostream>
using namespace std;
int main(void) {
  int x;
  cin >> x;
  for(int i = 0; ; ++i) {
    int base = i * 100;
    if(base > x) {
      cout << 0 << endl;
      break;
    }
    int mini = 0;
    int maxi = 5 * i;
    if(mini <= x-base && x-base <= maxi) {
      cout << 1 << endl;
      break;
    }
  }
  return 0;
}
