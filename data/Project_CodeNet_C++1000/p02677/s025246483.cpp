#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

void textIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}

int main()
{
    textIO();
    fastIO();

    long long a, b, h, m;
    cin >> a >> b >> h >> m;

    double hdeg = (h*30)+(m*0.5);
    double mdeg = (m*6);
    double degdiff = min(abs(mdeg-hdeg), abs(hdeg-mdeg));
    double ans = sqrt((a*a)+(b*b)-(2*a*b*cos((PI*degdiff)/180)));

    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}
