#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    int ans;

    ans = ((h2 - h1) * 60) + (m2 - m1) - k;
    // if (h1 <= h2)
    // {
    //     if (m2 >= m1)
    //     {
    //         ans = (h2 - h1) * 60;
    //         ans += (m2 - m1);
    //         ans -= k;
    //     }
    //     else if (m2 < m1)
    //     {
    //         ans = (h2 - h1 - 1) * 60;
    //         ans += (60 - m1);
    //         ans -= k;
    //     }
    // }
    // else if
    // {
    //     if (m2 >= m1)
    //     {
    //         ans = ((24 - h1) + h2) * 60;
    //         ans += (m2 - m1);
    //         ans -= k;
    //     }
    //     else if (m2 < m1)
    //     {
    //         ans = ((24 - h1) + h2 - 1) * 60;
    //         ans += (60 - m1);
    //         ans -= k;
    //     }
    // }
    cout
        << ans << endl;
    return (0);
}