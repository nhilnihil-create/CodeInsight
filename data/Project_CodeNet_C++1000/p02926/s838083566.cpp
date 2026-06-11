#include <bits/stdc++.h>
using namespace std;

using PP = pair<long, long>;

int n;
vector<PP> ps;

bool less_pi(PP p) {
  long x = p.first;
  long y = p.second;
  return y > 0 || y == 0 && x > 0;
}

bool comp_arg(PP a, PP b) {
  if (less_pi(a) && !less_pi(b)) return true;
  if (!less_pi(a) && less_pi(b)) return false;
  return a.first * b.second - a.second * b.first > 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) continue;
    ps.push_back(PP(x, y));
  }
  n = ps.size();
  sort(ps.begin(), ps.end(), comp_arg);
  
  long mx = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l + 1; r <= n + l; ++r) {
      PP sum(0, 0);
      
      for (int si = l; si < r; ++si) {
        int i = si % n;
        sum.first += ps[i].first;
        sum.second += ps[i].second;
      }
      
      mx = max(mx, sum.first * sum.first + sum.second * sum.second);
    }
  }
  cout << setprecision(16) << fixed << sqrt(mx) << endl;
}