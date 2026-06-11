#include <iostream>
#include <set>

typedef long long ll;

ll K;

int main() {
  std::cin >> K;
  ll x = 0;

  int ans = -1, c = 0;

  std::set<int> vis;
  while (true) {
    x = (10*x + 7) % K;
    //std::cout << x << "\n";
    c++;
    if (vis.find(x) != vis.end())
      break;
    if (x == 0) {
      ans = c;
      break;
    }
    vis.insert(x);
  }

  std::cout << ans << "\n";

  return 0;
}
