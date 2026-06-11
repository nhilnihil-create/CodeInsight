#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  long long  a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  long long dist = abs(a-b), power = (v-w)*t;
  puts(dist<=power?"YES":"NO");
  return 0;
}