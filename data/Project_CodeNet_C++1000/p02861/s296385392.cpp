#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i,0,n) {
    int x,y;
    cin >> x >> y;
    p[i] = P(x,y);
  }
  vector<int> v(n);
  rep(i,0,n) v[i] = i;
  double num = 0;
  do {
    rep(i,0,n-1) {
      num += sqrt((p[v[i+1]].first - p[v[i]].first)*(p[v[i+1]].first - p[v[i]].first) + (p[v[i+1]].second - p[v[i]].second)*(p[v[i+1]].second - p[v[i]].second));
    }
  } while (next_permutation(v.begin(), v.end()));
  double div = 1;
  rep(i,1,n+1) div *= i;
  double ans = num / div;
  printf("%.10lf\n", ans);
  return 0;
}
