#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  double a, b, x;
  double ans;
  cin >> a >> b >> x;
  // 最大容積
  double maxVolume = a*a*b;
  double sideArea = a*b;
  double bottomArea = a*a;
  double height;
  // xが水筒の半分より多いか少ないかで場合分け
  if(x<=maxVolume/2) {
    // 水は側面*高さ/2になる
    height = x*2/sideArea;
    ans = atan2(b,height) * 180 / M_PI;
  } else {
    double emptyVolume = maxVolume - x;
    height = emptyVolume*2/bottomArea;
    ans = atan2(height,a) * 180 / M_PI;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
