#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  int a;
  int b;
  int id;
};

int main() {
  int n;
  cin >> n;
  vector<node> vec(n);
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    vec[i] = {tmp, -tmp + i, i};
  }

  sort(vec.begin(), vec.end(),
       [](auto &lhs, auto &rhs) { return lhs.b < rhs.b; });

  long long cnt = 0;
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    auto c1 = [](auto &lhs, int rhs) { return lhs.b < rhs; };
    auto c2 = [](int lhs, auto &rhs) { return lhs < rhs.b; };
    auto itr1 = lower_bound(itr, vec.end(), itr->a + itr->id, c1);
    auto itr2 = upper_bound(itr, vec.end(), itr->a + itr->id, c2);
    cnt += itr2 - itr1;
  }

  cout << cnt << endl;
}