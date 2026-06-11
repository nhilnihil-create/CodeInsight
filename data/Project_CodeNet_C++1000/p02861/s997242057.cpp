#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll fac(int n) {
  ll ans = 1;
  while(n) {
    ans *= n;
    n--;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  ll d = fac(n);
  vector<pair<int, int>> vec;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
  }
  vector<double> edges;
  rep(i, n) {
    reps(j, i+1, n) {
      int x, y;
      x = vec[i].first - vec[j].first;
      y = vec[i].second - vec[j].second;
      edges.push_back(sqrt(x*x + y*y));
    }
  }
  double ans = 0;
  ll freq = fac(n-1);
  rep(i, (int)edges.size()) {
    ans += edges[i] * 2 * freq;
  }
  printf("%.8f\n", ans/d);


  return 0;
}