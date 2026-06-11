#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;

  double ans = (double)w*h/2;
  int num = (w==x*2 && h==y*2) ? 1 : 0;
  printf("%.10f %d\n", ans, num);
}