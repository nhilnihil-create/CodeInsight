#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <tuple>
#define FOR0(var, max) for (ui (var) = 0; (var) < (max); ++(var))
#define FOR_INV(var, min, max) for (ui (var) = (max) - 1; (var) + 1 > (min); --(var))
#define FORITER(var, iter) for (auto (iter) = (var).begin(); (iter) != (var).end(); (iter)++)
#define FORITER_INV(var, iter) for (auto (iter) = (var).rbegin(); (iter) != (var).rend(); (iter)++)

using namespace std;

using uc = unsigned char;
using ui = unsigned int;
using ul = unsigned long long int;

const static ui NMAX = 18;
const static ui SiMAX = 1<<18;
const static ui SMAX = 1000000000;

static ui N;
static multiset<ui> Si;

bool solve(void) {
  multiset<ui> confirmed;
  multiset<ui> remain = Si;

  auto first = max_element(remain.begin(), remain.end());
  confirmed.insert(*first);
  remain.erase(first);

  FOR0(i, N) {
    multiset<ui> next;

    FORITER_INV(confirmed, it) {
      auto t = remain.lower_bound(*it);
      if (t == remain.begin()) { // nothing possible slime
        return false;
      }
      t = prev(t);
      next.insert(*t);
      remain.erase(t);
    }

    FORITER(next, it) {
      confirmed.insert(*it);
    }
  }

  return confirmed.size() == Si.size();
}

int main(void) {
  cin >> N;
  FOR0(i, (1U << N)) {
    ui t;
    cin >> t;
    Si.insert(t);
  }
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}
