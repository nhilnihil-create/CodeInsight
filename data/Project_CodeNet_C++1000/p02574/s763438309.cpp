#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  int mx = 0;
  vector<int> nums(N);
  for (int n = 0; n < N; ++n) {
    cin >> nums[n];
    mx = max(mx, nums[n]);
  }
  vector<int> mods(mx+1);
  mods[1] = 1;
  for (int i = 2; i <= mx; ++i) {
    if (mods[i] != 0) {
      continue;
    }
    mods[i] = i;
    int tmp = i;
    while (tmp + i <= mx) {
      tmp += i;
      if (mods[tmp] != 0) continue;
      mods[tmp] = i;
    }
  }
  bitset<1000001> already;
  unordered_map<int, int> cnts;
  bool pairwise = true;
  for (int n : nums) {
    while (n > 1) {
      int tmp = mods[n];
      while (n % tmp == 0) {
        n /= tmp;
      }
      if (already.test(tmp)) {
        pairwise = false;
      }
      if (++cnts[tmp] == N) {
        cout << "not coprime" << endl;
        return 0;
      }
      already.set(tmp);
    }
  }
  if (pairwise) {
    cout << "pairwise coprime" << endl;
  } else {
    cout << "setwise coprime" << endl;
  }

  return 0;
}
