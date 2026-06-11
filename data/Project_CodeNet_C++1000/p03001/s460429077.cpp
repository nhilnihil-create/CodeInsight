#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    std::cout << std::fixed << std::setprecision(10);
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    printf("%lf %d\n", (double)W * (double)H / 2, (x + x == W) && (y + y == H));
    return (0);
}