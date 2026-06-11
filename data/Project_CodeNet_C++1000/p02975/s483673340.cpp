#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  // case1
  bool flag = true;
  rep(i,n) {
    if (a[i] != 0) {
      flag = false;
      break;
    }
  }

  if (flag){
    cout << "Yes" << endl;
    return 0;
  }

  // case2
  int c_0 = 0;
  set<ll> s;
  rep(i,n){
    if (a[i] == 0) {
      c_0++;
      continue;
    }
    s.insert(a[i]);
  }    
  if (c_0 == n/3 && n%3 == 0 && s.size() == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  // case3
  vector<pair<ll,ll>> v(0);
  set<ll> r;
  rep(i,n){
    if (r.count(a[i])) {
      rep(j,v.size()) if (v[j].first == a[i]) {
        v[j].second++;
        break;
      }
      continue;
    }
    r.insert(a[i]);
    v.push_back(make_pair(a[i],0));
    if (r.size() > 3) {
      cout << "No" << endl;
      return 0;
    }
  }  

  if (r.size() != 3) {
    cout << "No" << endl;
    return 0;
  }

  if ((v[0].second == v[1].second) && (v[1].second == v[2].second)){
    if (((v[0].first ^ v[1].first) ^ v[2].first) == 0){
        cout << "Yes" << endl;
        return 0;
    }
  }

  cout << "No" << endl;
  
  return 0;
}
