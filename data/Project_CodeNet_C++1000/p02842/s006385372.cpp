
#include <cstdio>
#include <iostream>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  for(int i = 0; i <= n; ++i) {
    int nn = i * 1.08;
    if(nn == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}
