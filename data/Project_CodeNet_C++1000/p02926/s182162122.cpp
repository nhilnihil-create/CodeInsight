#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<double, double> P;

double arct(P x) {
  double a = x.first, b = x.second;
  if (a==0&&b==0) return 0;
  double result = acos(a/sqrt(a*a+b*b));
  if (b<0) result = 2*M_PI - result;
  return result;
}

double rad(P x, P y) {
  double rx = arct(x), ry = arct(y);
  if (rx>ry) ry += 2*M_PI;
  return ry-rx;
}

int main() {
  int N; cin >> N;
  P pos[N];
  rep(i,N) cin >> pos[i].first >> pos[i].second;
  sort(pos, pos+N, [](const P& x, const P& y) {return arct(x) < arct(y);});
  // rep(i,N) cout << pos[i].first << " " << pos[i].second << endl;
  double result = 0;
  rep(i,N) {
    double nx = 0, ny = 0;
    int now = i, count = 0;
    while (rad(pos[i],pos[now])<=M_PI&&count!=N) {
      nx += pos[now].first; ny += pos[now].second;
      double dis = sqrt(nx*nx+ny*ny);
      result = max(result, dis);
      now++; now%=N;
      count++;
    }
  }
  cout << fixed << setprecision(10) << result << endl;
  return 0;
}