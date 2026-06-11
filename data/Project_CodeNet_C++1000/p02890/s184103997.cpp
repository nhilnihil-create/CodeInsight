#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v, ans, sum, memo;
map<long long, long long> mp;

void solve();

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    ++mp[x];
  }
  solve();
  for(int i = 0; i < n; ++i) cout << ans[i] << endl;
  return 0;
}

void solve() {
  ans.assign(n, 0);
  for(auto now : mp) v.push_back(now.second);
  sort(v.begin(), v.end());
  sum = v;
  long long vsize = v.size();
  for(int i = 1; i < vsize; ++i) sum[i] += sum[i - 1];
  memo.assign(n, 0);
  for(int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), i + 1);
    long long id = it - v.begin();
    if(--id >= 0) memo[i] += sum[id];
    memo[i] += (vsize - id - 1) * (i + 1);
    memo[i] /= i + 1;
  }
  for(int i = 0; i < n; ++i) {
    auto it = lower_bound(memo.begin(), memo.end(), i,
                          greater<long long>());
    ans[i] = it - memo.begin();
  }
}