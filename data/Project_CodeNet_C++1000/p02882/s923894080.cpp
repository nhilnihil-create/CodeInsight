#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
#define print(ans) cout << fixed << setprecision(15) << ans << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
typedef long long ll;
typedef vector<ll> vi;

double degree(double rad){
  double pi = 3.1415926535897932384626;
  return rad*360.0/2.0/pi;
}



int main() {
  double a,b,x;
  cin >> a >> b >> x;
  if (a*a*b < 2.0*x){
    print(degree(atan( -2.0*x/a/a/a + 2.0*b/a)));
  }
  else{
    print(degree(atan(a*b*b/2.0/x)));
  }
}
