#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

int main() {
  ll a, speed1;
  ll b, speed2;
  std::cin >> a >> speed1;
  std::cin >> b >> speed2;
  ll t;
  std::cin >> t;
  if(speed1 <= speed2) 
    std::cout << "NO";
  else if(t < fabs(a - b) / (speed1 - speed2)) {
    std::cout << "NO";
  } else
    std::cout << "YES";
}
