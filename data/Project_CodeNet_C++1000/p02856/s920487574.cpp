#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<ll,ll>;

ll merge(ll a, ll b) {
  if(a + b <= 9) return a + b;
  else return (a + b)/10 + ((a + b) % 10);
}

ll dfs(vector<P> v) {
  if(v.size() == 1 && v[0].second == 1) return 0;
  ll res = 0;
  vector<P> u;
  int p = 0;
  while(p < v.size()) {
    if(v[p].second > 1) {
      u.push_back(P(merge(v[p].first,v[p].first),v[p].second/2));
      if(v[p].first >= 5) res += (v[p].second/2) *2;
      else res += v[p].second/2;
      if(v[p].second % 2) u.push_back(P(v[p].first,1));
      p++;
    } else if(p+1 < v.size() && v[p+1].second == 1) {
      u.push_back(P(merge(v[p].first,v[p+1].first),1));
      if(v[p].first + v[p+1].first <= 9) res += 1;
      else res += 2;
      p += 2;
    } else {
      u.push_back(v[p]);
      p++;
    }
  }
  return res + dfs(u);
}

int main(){
  int m;
  cin >> m;
  vector<P> v(m);
  rep(i,m) cin >> v[i].first >> v[i].second;
  cout << dfs(v) << endl;
  return 0;
}