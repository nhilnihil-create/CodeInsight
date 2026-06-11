#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int k;
  cin >> k;

  queue<vector<int> > list;
  vector<int> seq;

  if (k < 10) {
    cout << k << endl;
    return 0;
  }

  rep(i, 9) { list.push({i + 1}); }

  k -= 9;

  while (k > 0) {
    seq = list.front();
    list.pop();

    int first = max(0, seq.back() - 1);
    int last = min(9, seq.back() + 1);
    for (int i = first; i <= last; i++) {
      vector<int> new_seq(seq);
      new_seq.push_back(i);
      list.push(new_seq);
      k--;

      if (k == 0) {
        rep(j, new_seq.size()) { cout << new_seq[j]; }
      }
    }
  }

  return 0;
}