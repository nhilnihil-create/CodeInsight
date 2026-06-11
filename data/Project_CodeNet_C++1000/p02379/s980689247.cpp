#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ll;
    ll = (x2 - x1)*(x2 - x1) + (y2-y1)*(y2-y1);
    cout << fixed;
    std::cout << setprecision(8) <<std::sqrt(ll) << std::endl;
}
