#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> p(n);
  rep(i,0,n) {
    int a,b;
    cin >> a >> b;
    p[i] = P(a,b);
  }
  sort(p.begin(), p.end());
  priority_queue<int> q;
  int ans = 0;
  int j = 0;
  rep(i,1,m+1) {
    while(p[j].first == i) {
      q.push(p[j].second);
      j++;
      if (j == n) j = 0;
    }
    if (q.empty()) continue;
    int k = q.top(); q.pop();
    ans += k;
  }
  cout << ans << endl;
  return 0;
}
