#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M;
  cin >> N >> M;
  // vector <int> s(M);
  // vector <int> c(M);
  vector <P> p(M);
  rep(i,M) cin >> p[i].first >> p[i].second;
  rep(x,1000){
    bool ok = true;  //フラグ
    vector <int> d(1, x%10);  //各桁を格納
    int nx = x / 10;
    while (nx){
      d.push_back(nx%10);
      nx /= 10;
    }
    reverse(d.begin(), d.end());
    if (d.size() != N) continue;
    rep(i,M){
      if (d[p[i].first - 1] != p[i].second) ok = false;
    }
    if (ok){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
