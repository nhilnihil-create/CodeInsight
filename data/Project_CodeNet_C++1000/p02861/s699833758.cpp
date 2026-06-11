#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<pair<double, double>> xy;
  vector<double> p(n);
  rep(i,n){
    int x, y;
    cin >> x >> y;
    xy.push_back({x, y});
    p[i] = i;
  }
  double sum = 0;
  double cnt = 0;
  do {
    // rep(i,n) cout << p[i] << " ";
    // cout << endl;
    double dist = 0;
    cnt++;
    for(int i=0; i<n-1; ++i){
      double pd = sqrt((xy[p[i]].first - xy[p[i+1]].first)*(xy[p[i]].first - xy[p[i+1]].first) + ((xy[p[i]].second - xy[p[i+1]].second)*(xy[p[i]].second - xy[p[i+1]].second)));
      dist += pd;
      // printf("%.10f,%f ", dist,cnt);
      // cout << dist << " " << cnt << endl;
      // cout << '(' << xy[i].first << ',' << xy[i].second << ')' << " ";
      // cout << i << " ";
    }
    sum += dist;
    // cout << endl;
  }while(next_permutation(p.begin(), p.end()));
  // for(auto x : xy) cout << x.first << " " << x.second << endl;
  double ans = sum / cnt;
  printf("%.12f\n",ans);
  return 0;
}