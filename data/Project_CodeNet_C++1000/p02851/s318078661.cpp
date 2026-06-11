#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    a.at(i)--;
  }
  for (int i = 0; i < n; i++) {
    s.at(i + 1) = (s.at(i) + a.at(i)) % k;
  }
  long long ans = 0;
  map<int, int> mp;
  queue<int> q;
  for (int i = 0; i < n + 1; i++) {
    ans += mp[s.at(i)];
    mp[s.at(i)]++;
 
    q.push(s.at(i));
    if (q.size() == k) {
      mp[q.front()]--;
      q.pop();
    }
  }
  cout << ans;
  return 0;
}