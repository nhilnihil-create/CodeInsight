#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long double A, long double B, long double H, long double M)
{
    double tyo = (H / 12 + M / 60 / 12) * 2 * M_PI;
    double tan = M / 60 * 2 * M_PI;
    double ans = A * A + B * B - 2 * A * B * cos((tyo - tan));
    ans = sqrt(ans);
    printf("%.10lf\n", ans);
}

signed main()
{
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long H;
    scanf("%lld", &H);
    long long M;
    scanf("%lld", &M);
    solve(A, B, H, M);
    return 0;
}
