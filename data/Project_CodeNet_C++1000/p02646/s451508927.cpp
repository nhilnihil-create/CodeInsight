#include <iostream>
#include <string>

using namespace std;

int main() {
  long long a, v, b, w, t = 0;
  cin >> a;
  cin >> v;
  cin >> b;
  cin >> w;
  cin >> t;

  if (abs(a - b) <= (v - w) * t) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}