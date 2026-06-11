#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

struct monster {
  long X;
  long H;
};

int main(int argc, char** argv) {
  int N;
  long D, A;
  std::vector<monster> monsters;
  
  cin >> N >> D >> A;

  
  for (int i = 0; i < N; ++i) {
    monster m;
    cin >> m.X >> m.H;
    monsters.push_back(m);
  }

  std::sort(monsters.begin(), monsters.end(), [](const monster& x, const monster& y) {
                                                return x.X < y.X;
                                              });
  // for (monster m: monsters)
  //   cout << m.X << " " << m.H << endl;
  long result = 0;

  for (unsigned i = 0; i < monsters.size(); ++i) {
    if (monsters[i].H % A == 0) {
      monsters[i].H /= A;
    } else {
      monsters[i].H = monsters[i].H / A + 1;
    }
  }

  deque<long> cumsum_x;
  deque<long> cumsum_h;
  long cumsum = 0;

  
  for (unsigned i = 0; i < monsters.size(); ++i) {
    long x = monsters[i].X;
    // cout << cumsum_x.front() << " " << x - 2 * D << endl;
    while (!cumsum_x.empty() && cumsum_x.front() < x - 2 * D) {
      cumsum -= cumsum_h.front();
      cumsum_x.pop_front();
      cumsum_h.pop_front();
    }

    long h = monsters[i].H;

    // cout << x << " " << h << " " << cumsum << endl;
    if (cumsum >= h) {
      continue;
    } else {
      cumsum_x.push_back(x);
      cumsum_h.push_back(h - cumsum);
      result += h - cumsum;
      cumsum += h - cumsum;
    }
  }
  
  // for (unsigned i = 0; i < monsters.size(); ++i) {
  //   long at = monsters[i].X;
  //   long h = monsters[i].H;
  //   if (h <= 0)
  //     continue;

  //   result += h;
  //   for (unsigned j = i + 1; j < monsters.size() && monsters[j].X <= at + 2* D; ++j) {
  //     monsters[j].H -= h;
  //   }
  // }

  cout << result << endl;
  return 0;
}
