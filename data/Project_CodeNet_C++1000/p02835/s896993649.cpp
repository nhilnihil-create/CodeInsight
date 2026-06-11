#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a + b + c >= 22) {
    cout << "bust" << endl;
  }
  else {
    cout << "win" << endl;
  }
  return 0;
}
