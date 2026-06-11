#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
a^2 = b^2 + c^2 - 2bc conA

*/
double PI = acos(-1);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll A, B, H, M; cin >> A >> B >> H >> M;
  double ans;
  double m;
  double h;
  m = 6 * M;
  h = 30 * H;
  h += 0.50 * M;
  double theta = abs(m-h);
  if (theta > 180)
    theta = 360 - theta;
//  cout<<theta<<endl;
  theta /= 180.0;
  theta *= PI;
  ans = A*A + B*B - 2 * A * B * cos(theta);
  ans = sqrt(ans);
  cout << fixed << setprecision(10) << ans << endl;
}
