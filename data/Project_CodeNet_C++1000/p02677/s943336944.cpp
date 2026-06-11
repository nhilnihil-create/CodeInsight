#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define printYes() printf("Yes\n")
#define printNo() printf("No\n")
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4Int(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
typedef long long ll;
const int INF = 1001001001;
using namespace std;
 
int main() {
    long double a, b, h, m;
    scanf("%Lf %Lf %Lf %Lf",&a,&b,&h,&m);
    long double hdeg, mdeg, hrad, mrad, hx, hy, mx, my;
    hdeg = 360.0L / 12.0L * h + (360.0L / 12.0L) / 60.0L * m;
    mdeg= 360.0L / 60.0L * m;
    hrad = hdeg * M_PI / 180.0L;
    mrad = mdeg * M_PI / 180.0L;
    hx = cos(hrad) * a;
    hy = sin(hrad) * a;
    mx = cos(mrad) * b;
    my = sin(mrad) * b;
    long double dist = pow(
        abs(hy - my) * abs(hy - my) +
        abs(hx - mx) * abs(hx - mx), 0.5);
    printf("%.9Lf\n", dist);
    return 0;
}