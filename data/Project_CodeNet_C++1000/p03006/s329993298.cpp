#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<pair<int,int>> x(N);
  rep(i, N) cin >> x[i].first >> x[i].second;
  sort(all(x));
  
  map<pair<int,int>,int> map;
  
  rep(i, N) repp(j, i+1, N) {
    map[make_pair(x[i].first-x[j].first, x[i].second-x[j].second)]++;
  }
  
  int a = 0;
  for(auto p : map) a = max(a, p.second);
  cout << N - a << endl;

}