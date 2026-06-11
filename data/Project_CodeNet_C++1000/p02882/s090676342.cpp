#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    double a, b, x, theta;
    cin >> a >> b >> x;
    if (a * b * a > x * 2) theta = atan(b*b*a*0.5/x);
    else theta = atan(2*b/a - 2*x/(a*a*a));
    theta = theta * 180 / M_PI;
    printf("%.10f\n", theta);
    return 0;
}