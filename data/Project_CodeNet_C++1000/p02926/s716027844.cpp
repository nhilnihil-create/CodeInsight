#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct F{
  ld x;
  ld y;
  bool operator< (const F &R) const {
    return atan2(x,y) < atan2(R.x, R.y);
  }
};

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<F> ps(n);
  for(int i = 0 ; i < n ; i ++ ){
    cin >> ps[i].x >> ps[i].y;
  }
  sort(ps.begin(), ps.end());
  ld ans = 0;
  ld cx, cy;
  for(int i = 0 ; i < n; i ++ ){
    cx = 0, cy = 0;
    for(int j = 0 ; j < n; j ++ ){
      cx += ps[(i+j)%n].x;
      cy += ps[(i+j)%n].y;
      ans = max(ans, cx * cx + cy * cy);
    }
  }
  cout << fixed << setprecision(15) << sqrt(ans) << "\n";
  return 0;
}