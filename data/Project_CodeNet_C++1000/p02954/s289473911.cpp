/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct Vertex {
  int64_t distance{INT64_MAX};
  vector<pair<int64_t, int64_t>> edges;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  int32_t N = static_cast<int32_t>(S.length());
  const char *const text = S.c_str();

  vector<int32_t> loop_left;
  vector<int32_t> final_number(N, 0);
  int32_t store_index = 0;
  for (int32_t i = 0; i < N; ++i) {
    if (i == N - 1) {
      while (store_index < N) {
        const int32_t previous_loop_left = loop_left[loop_left.size() - 1];
        if ((store_index - previous_loop_left) % 2 == 0) {
          final_number[previous_loop_left]++;
        } else {
          final_number[previous_loop_left + 1]++;
        }
        ++store_index;
      }
    } else if (text[i] == 'R' && text[i + 1] == 'L') {
      loop_left.push_back(i);
      while (store_index <= i) {
        if (text[store_index] == 'R') {
          if ((i - store_index) % 2 == 0) {
            final_number[i]++;
          } else {
            final_number[i + 1]++;
          }
        } else {
          const int32_t previous_loop_left = loop_left[loop_left.size() - 2];
          if ((store_index - previous_loop_left) % 2 == 0) {
            final_number[previous_loop_left]++;
          } else {
            final_number[previous_loop_left + 1]++;
          }
        }
        ++store_index;
      }
      final_number[store_index]++;
      ++store_index;
    }
  }
  for (int32_t i = 0; i < N; ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << final_number[i];
  }
  cout << endl;

  return 0;
}
