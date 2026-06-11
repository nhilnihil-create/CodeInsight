#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   double A, B, H, M;
   cin >> A >> B >> H >>M;
   double la = 0, lb = 0;
   la = (H / 12.0 + M / 720.0);
   lb = (M / 60.0);
   double div = abs(la - lb);
   if(div > 0.5) {
      div = 1.0 - (div);
   }

   double abcos = cos(abs(la-lb) * M_PI * 2);
   double ans = sqrt((A*A + B*B - 2*A*B*abcos));
   cout << fixed << setprecision(12) << ans << endl;

}
