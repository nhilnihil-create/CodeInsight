#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  map<int, int> cnt;
  int maxi = 0;
  for (int i = 0; i < (1 << n); i++) {
    int val;
    cin >> val;
    cnt[val]++;
    maxi = max(maxi, val);
  }
  queue<int> q;
  if (cnt[maxi] != 1) {
    cout << "No\n";
    return 0;
  }
  cnt.erase(maxi);
  q.push(maxi);
  while (!cnt.empty()) {
    int x = q.front();
    q.pop();
    auto it = cnt.lower_bound(x);
    if (it == cnt.begin()) {
      cout << "No\n";
      return 0;
    }
    it = prev(it);
    q.push(it->first);
    it->second--;
    if (it->second == 0) {
      cnt.erase(it);
    }
    q.push(x);
  }
  cout << "Yes\n";
  return 0;
}
