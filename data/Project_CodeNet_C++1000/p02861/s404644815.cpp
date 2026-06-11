#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vi x(n), y(n);
  rep(i,n) cin >> x.at(i) >> y.at(i);
  auto dist = [&](int a, int b){
    int dx = x.at(b) - x.at(a);
    int dy = y.at(b) - y.at(a);
    return sqrt(dx*dx+dy*dy);
  };

  vi p(n);
  rep(i,n) p.at(i) = i;
  double len = 0;
  int cnt = 0;
  do {
    rep(i,n-1){
      len += dist(p.at(i), p.at(i+1));
    }
    cnt++;
  } while(next_permutation(p.begin(), p.end()));

  double ans = len / cnt;
  printf("%.10f\n", ans);
  return 0;
}
