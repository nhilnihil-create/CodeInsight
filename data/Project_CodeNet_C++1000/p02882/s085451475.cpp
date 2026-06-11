#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    if (2.0*x <= a*a*b) printf("%.10f\n", 180.0*atan(a*b*b/2/x)/M_PI);
    else printf("%.10f\n", 180.0*atan(2.0*(b-x/a/a)/a)/M_PI);

    return 0;
}