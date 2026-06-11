#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P = pair<long long, long long>;

long long n;
vector<long long> s;
map<long long, long long, greater<long long>> mp;

bool solve();

int main() {
  cin >> n;
  s.resize((1LL << n));
  for(long long i = 0; i < (1LL << n); ++i) cin >> s[i];
  sort(s.begin(), s.end(), greater<long long>());
  if(solve())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

bool solve() {
  priority_queue<long long> pq, dummy;
  pq.push(s[0]);
  for(int i = 1; i < s.size(); ++i) ++mp[s[i]];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < (1LL << i); ++j) {
      long long now = pq.top();
      pq.pop();
      dummy.push(now);
      auto it = mp.upper_bound(now);
      if(it == mp.end()) return 0;
      if(--(*it).second == 0) mp.erase(it);
      dummy.push((*it).first);
    }
    while(!dummy.empty()) {
      pq.push(dummy.top());
      dummy.pop();
    }
  }

  return 1;
}
