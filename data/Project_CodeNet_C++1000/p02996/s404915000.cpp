#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<P> pairs;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    pairs.push_back(make_pair(b, a));
  }
  sort(pairs.begin(), pairs.end());
  bool flag = true;
  ll now_time = 0, dead_line = 0;
  rep(i, n) {
    now_time += pairs[i].second;
    dead_line = pairs[i].first;
    if (now_time > dead_line) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}