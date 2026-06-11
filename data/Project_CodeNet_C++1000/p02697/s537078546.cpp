#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int kMax = 200000;
bool used[kMax];

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> even;
  vector<pair<int, int>> odd;
  for (int i = 0; i < M; ++i) {
    if (i % 2 == 0) {
      if (even.empty()) {
        even.push_back(make_pair(0, 1));
      } else {
        pair<int, int> last = even.back();
        even.push_back(make_pair(last.first - 1, last.second + 1));
      }
    } else {
      if (odd.empty()) {
        odd.push_back(make_pair(0, 2));
      } else {
        pair<int, int> last = odd.back();
        odd.push_back(make_pair(last.first - 1, last.second + 1));
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    if (i % 2 == 0) {
      pair<int, int> p = even[i / 2];
      int even_min = even.back().first;
      cout << (p.first - even_min + 1) << " " << (p.second - even_min + 1) << endl;
    } else {
      pair<int ,int> p = odd[i / 2];
      int odd_min = odd.back().first;
      int even_max = even.back().second - even.back().first;
      int adjust = -odd_min + even_max + 1;
      cout << (p.first + adjust + 1) << " " << (p.second + adjust + 1) << endl;
    }
  }
}