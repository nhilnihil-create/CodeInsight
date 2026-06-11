#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORr(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

int main(void){
  int n;
  cin >> n;
  vector<int> p(n);
  REP(i, n){
    int t;
    cin >> t;
    t--;
    p[i] = t;
  }

  vector<int> idx(n);
  REP(i, n) idx[p[i]] = i;

  set<int> s;
  ll ans = 0;
  FORr(x, n-1, -1){
    int i = idx[x];
    
    ll c = 0;
    s.insert(i);
    vector<int> l(2,-1);
    vector<int> r(2, n);
    auto itr = s.find(i);
    REP(j, 2){
      if(itr == s.begin()) break;
      itr--;
      l[j] = *itr;
    }
    itr = s.find(i);
    REP(j, 2){
      itr++;
      if(itr == s.end()) break;
      r[j] = *itr;
    }
    vector<int> ls(2), rs(2);
    ls[0] = i-l[0];
    ls[1] = l[0]-l[1];
    rs[0] = r[0]-i;
    rs[1] = r[1]-r[0];
    c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];

    ans += c*(x+1);
  }
  cout << ans << endl;

  return 0;
}