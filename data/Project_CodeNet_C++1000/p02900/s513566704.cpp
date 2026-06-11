#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;

  list<ll> vec = {1};
  int i = 2;
  while (true) {
    if (sqrt(a) + 1 < i) {
      if (a != 1)
        vec.push_back(a);
      break;
    }
    else if (a / i * i == a) {
      vec.push_back(i);
      a /= i;
    }
    else
      ++i;
  }

  for (auto itr = vec.begin(); itr != vec.end();) {
    if (b / *itr * *itr == b)
      ++itr;
    else
      itr = vec.erase(itr);
  }

  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  cout << vec.size() << endl;
}