#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535897932384626433;

ld solve(ld a, ld b, ld theta) {
  if (b*cos(theta) > a*sin(theta)) {
    ld ans = 0;
    ans += a*a*a*tan(theta)/2;
    //cerr << " >>>> " << b-a*tan(theta) << endl;
    ans += (b-a*tan(theta))*a*a;
    return ans;
  } else {
    //cerr << " b " << b << " b*a " << b*a << " b*a/tan(theta) " << b*a/tan(theta) << " b*a/tan(theta)*a " << b*a/tan(theta)*a << " THETA " << theta << endl;
    return b*b/tan(theta)*a/2;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ld a, b, x;
  cin >> a >> b >> x;

  ld lo = 0, hi = PI/2;

  for (int i=0; i<50; ++i) {
    ld mid = (lo+hi)/2;
    ld cap = solve(a, b, mid);
    if (cap > x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  //cerr << "~~ " << endl;
  //cerr << " :: " <<fixed << setprecision(10) << solve(a, b, 89.7834636934/180*PI) << endl;
  //cerr << " :: " <<fixed << setprecision(10) << solve(a, b, 89.81/180*PI) << endl;
  cout << fixed << setprecision(10) << hi*180/PI << endl;

  return 0;
}
