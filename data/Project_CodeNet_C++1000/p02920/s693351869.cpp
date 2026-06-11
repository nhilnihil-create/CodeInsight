#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <tuple>
#include <set>

using namespace std;

struct slim {
  int left_split_count;
  int max_value_can_be_used;
};

int main() {
  int n;
  cin >> n;
  vector<int> ss(pow(2,n));

  for (int i = 0; i < pow(2,n); i++) {
    cin >> ss[i];
  }
  sort(ss.begin(), ss.end(), greater<>());

  vector<priority_queue<int>> current_slims(n+1, priority_queue<int>());
  current_slims[n].push(pow(10, 9));

  bool result = true;

  for (const auto& s : ss) {
    bool is_set_s = false;
    // cout << "s: " << s << endl;
    for (int i = n; i >= 0; i--) {
      // cout << "i: " << i << endl;
      if (current_slims[i].empty()) {
        // cout << "continue because empty" << endl;
        continue;
      }

      if (current_slims[i].top() < s) {
        // cout << "continue because too small" << endl;
        continue;
      }
      // cout << "can_set" << endl;

      int value = current_slims[i].top();
      current_slims[i].pop();

      for (int j = 0; j < i; j++) {
        current_slims[j].push(s-1);
      }

      if ((i == current_slims.size()-1) && current_slims[i].empty()) {
        current_slims.pop_back();
      }

      is_set_s = true;
      break;
    }

    if (!is_set_s) {
      result = false;
      break;
    }
  }

  cout << (result ? "Yes" : "No") << endl;
}
