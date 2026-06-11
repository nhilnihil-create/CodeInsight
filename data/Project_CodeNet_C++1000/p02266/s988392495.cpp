#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
using namespace std;

stack<int> mizu_whole;
stack<pair<int, int> > mizu;
vector<int> ans;
int sum;

void solve() {
  char c;
  for (int i = 0; cin >> c; ++i) {
    if (c == '\\') {
      mizu_whole.push(i);
    } else if (c == '/' && !mizu_whole.empty()) {
      int left = mizu_whole.top();
      mizu_whole.pop();
      int area = i - left;
      while (!mizu.empty() && left <= mizu.top().first) {
        area += mizu.top().second;
        mizu.pop();
      }
      mizu.push(make_pair(left, area));
    }
  }
  while (!mizu.empty()) {
    sum += mizu.top().second;
    ans.push_back(mizu.top().second);
    mizu.pop();
  }
  reverse(all(ans));
  cout << sum << endl << ans.size();
  for (int area : ans) {
    cout << " " << area;
  }
  cout << endl;
}
int main() {
  solve();
  return 0;
}

