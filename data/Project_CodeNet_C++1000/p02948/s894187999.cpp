#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005, A = 100005;

int n, m, a[N], b[N];

vector<int> rwd[A]; // rwd[i]: i日後に得られる報酬
multiset<int> job;

int main() {
  cin >> n >> m;
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) rwd[a[i]].push_back(b[i]);
  int ans = 0;
  rep(i, m+1) {
    rep(j, rwd[i].size()) job.insert(-rwd[i][j]);
    auto itr = job.begin();
    if (itr == job.end()) continue;
    ans -= *itr;
    job.erase(itr);
  }
  cout << ans << endl;
  return 0;
}