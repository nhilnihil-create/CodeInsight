#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<double> c;
  rep(i, n) {
    double v;
    cin >> v;
    c.push_back(v);
  };
  rep(j, n-1) {
    set<int> s;
    sort(c.begin(), c.end());
    double x, y;
    rep(i, c.size()) {
      if(!s.count(i)) {
        x = c[i];
        s.insert(i);
        break;
      }
    }
    rep(i, c.size()) {
      if(!s.count(i)) {
        y = c[i];
        s.insert(i);
        break;
      }
    }
    vector<double> c3;
    rep(i, c.size()) {
      if(s.count(i)) continue;
      c3.push_back(c[i]);
    }
    c3.push_back((x+y)/2);
    c = c3;
  }
  cout << c[0] << endl;
  return 0;
}