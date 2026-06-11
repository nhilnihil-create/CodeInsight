#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int a, b, c, k;
  int count = 0;
  cin >> a >> b >> c >> k;
  while(a >= b) {
    b *= 2;
    count++;
  }
  while(b >= c) {
    c *= 2;
    count++;
  }
  if (count <= k) printf("Yes\n");
  else printf("No\n");
}