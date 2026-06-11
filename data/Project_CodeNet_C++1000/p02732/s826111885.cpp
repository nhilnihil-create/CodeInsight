#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  unordered_map<int, int> map;
  vector<int> balls;

  rep(i, n) {
    int a;
    cin >> a;
    map[a]++;
    balls.push_back(a);
  }

  ll total = 0;

  for (auto bucket : map) {
    ll count = bucket.second;
    total += (count * (count - 1)) / 2;
  }

  for (auto ball : balls) {
    int count = map[ball];
    cout << total - (count - 1) << endl;
  }

  return 0;
}
