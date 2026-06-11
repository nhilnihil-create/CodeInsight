#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main () {
  int n;
  cin >> n;
  int slime_num = pow(2, n);
  int s[slime_num];
  multiset <int> slime;
  for (int i = 0; i < slime_num; i++) {
    cin >> s[i];
    slime.insert(s[i]);
  }
  auto max_itr = slime.end();
  max_itr--;
  int max = *max_itr;
  multiset <int> born;
  born.insert(max);
  slime.erase(max_itr);
  for (int i = 0; i < n; i++) {
    multiset <int> tmp;
    for (auto j = born.begin(); j != born.end(); j++) {
      int size = *j;
      auto itr = slime.lower_bound(size);
      if (itr == slime.begin()) {
        puts("No");
        return 0;
      }
      itr--;
      int new_size = *itr;
      slime.erase(itr);
      tmp.insert(new_size);
    }
    for (auto j = tmp.begin(); j != tmp.end(); j++) {
      int size = *j;
      born.insert(size);
    }
  }
  puts("Yes");
  return 0;
}
