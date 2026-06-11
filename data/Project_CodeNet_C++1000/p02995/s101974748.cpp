#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll cmn, cmx, dmn, dmx, cdmn, cdmx;
  cmn = (a+c-1)/c;
  cmx = b/c;
  dmn = (a+d-1)/d;
  dmx = b/d;
  ll cd = lcm(c, d);
  cdmn = (a+cd-1)/cd;
  cdmx = b/cd;
  //cout << cmx << cmn << endl;
  //cout << dmx << dmn << endl;
  //cout << cdmx << cdmn << endl;
  ll ans = b-a+1 - ((cmx-cmn+1) + (dmx-dmn+1) - (cdmx-cdmn+1));
  cout << ans << endl;
}
