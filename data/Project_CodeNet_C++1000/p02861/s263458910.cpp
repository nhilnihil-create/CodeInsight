#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  auto dist = [&](int i, int j) {
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];
    return sqrt(dx*dx+dy*dy);
  };
  vector<int> p(n);
  rep(i,n) p[i] = i;
  double len = 0;
  int cnt = 0;
  do {
    rep(i,n-1) {
      len += dist(p[i],p[i+1]);
    }
    cnt++;
  } while (next_permutation(p.begin(), p.end()));
  double ans = len/cnt;
  printf("%.10f\n", ans);
  return 0;
}