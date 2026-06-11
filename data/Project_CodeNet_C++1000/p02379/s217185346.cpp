#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {FIN
    
    double x1, x2, y1, y2, d1, d2;
    cin >> x1 >> y1 >> x2 >> y2;
    d1 = abs(x1 - x2);
    d2 = abs(y1 - y2);
    cout << fixed << setprecision(6) << sqrt(d1 * d1 + d2 * d2) << "\n";
    return 0;
}
