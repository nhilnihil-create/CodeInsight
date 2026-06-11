#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> m, p;
  vector<P> ans;
  m.push_back(a[0]);
  p.push_back(a[n - 1]);
  for(int i = 1; i < n - 1; i++){
    if(a[i] < 0) m.push_back(a[i]);
    else p.push_back(a[i]);
  }

  int sum = m[0];
  for(int pi = 1; pi < p.size(); pi++){
    ans.push_back(make_pair(sum, p[pi]));
    sum -= p[pi];
  }

  ans.push_back(make_pair(p[0], sum));
  sum = p[0] - sum;
  for(int mi = 1; mi < m.size(); mi++){
    ans.push_back(make_pair(sum, m[mi]));
    sum -= m[mi];
  }
  cout << sum << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
