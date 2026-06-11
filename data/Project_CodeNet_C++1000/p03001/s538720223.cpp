#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC130 C - Rectangle Cutting
// 2020.06.19

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  double W, H, x, y; cin >> W >> H >> x >> y;
  double ans = W*H/2;
  bool flag;
  if(x*2 == W && y*2 == H){
    flag = true;
  }else{
    flag = false;
  }
  cout << fixed << setprecision(10) << ans << " ";
  cout << flag << endl;
}