#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> pq;
  vector<P> job;
 
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    job.emplace_back(make_pair(a, b));
  }
  sort(job.begin(), job.end(), greater<P>());
  int res = 0;
  for (int i = 1; i <= m; i++) {
    auto p = job.back();
    while (i >= p.first && job.size() > 0) {
      job.pop_back();
      pq.push(p.second);
      p = job.back();
    }
    if (!pq.empty()) {
      res += pq.top();
      pq.pop();
    }
  }
  cout << res << endl;
  return 0; 
} 