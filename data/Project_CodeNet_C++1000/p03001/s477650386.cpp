#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  ll w, h, x, y;
  cin >> w >> h >> x >>  y;

  int flg = 0;

  if(x * 2 == w && y * 2 == h){
    flg = 1;
  }

  double ans = (double)h * w/2;


  cout << fixed << setprecision(10) <<  ans << " " << flg << endl;
  return 0;
}
