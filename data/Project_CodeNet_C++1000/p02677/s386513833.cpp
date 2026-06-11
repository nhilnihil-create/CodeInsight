#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  double a,b,h,m;cin >> a>>b>>h>>m;
  double pi = 4.0d * atan(1.0d);
  double ax = a * sin(2.0d * pi * (double)h / 12.0d + 2.0d * pi * (double)m / 720.0d);
  double ay = a * cos(2.0d * pi * (double)h / 12.0d + 2.0d * pi * (double)m / 720.0d);
  double bx = b * sin(2.0d * pi * (double)m / 60.0d );
  double by = b * cos(2.0d * pi * (double)m / 60.0d );
  double out = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
  cout << fixed << setprecision(15) << out << endl;
  return 0;
}
