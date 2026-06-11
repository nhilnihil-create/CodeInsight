#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    long double a, b, h, m;
    cin >> a >> b >> h >> m;
    long double theta = abs((h+m/60)/12*2*M_PI - m/60*2*M_PI);
    printf("%20.20Lf\n", sqrt(abs(a*a + b*b - 2*a*b*cos(theta))));
}