#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N;
  cin >> N;
  map<int64_t, int64_t> uniq;
  // map<int, int> uniq;
  for (int64_t i = 0; i < N; i++) {
    int64_t x;
    cin >> x;
    if (uniq.count(x) == 0) {
      uniq[x] = 0;
    }
    uniq[x]++;
  }
  vector<int64_t> search;
  unordered_set<int64_t> notdiv;
  for (auto x : uniq) {
    search.push_back(x.first);
    notdiv.insert(x.first);
  }
  int64_t maxnum = search[search.size() - 1];
  for (auto s : search) {
    for (int64_t i = 2;; i++) {
      int64_t v = s * i;
      if (v > maxnum) {
        break;
      }
      if (notdiv.count(v) > 0) {
        notdiv.erase(v);
      }
    }
  }
  int64_t result = 0;
  for (auto nd : notdiv) {
    if (uniq.at(nd) == 1) {
      result++;
    }
  }
  cout << result << endl;
}
