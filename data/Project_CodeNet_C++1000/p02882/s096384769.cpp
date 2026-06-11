#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int a, b, x;
    cin >> a >> b >> x;
    double theta;
    if (a * a * b <= 2 * x)
    {
        theta = atan(2.0 * (a * a * b - x) / (a * a * a));
    }
    else
    {
        theta = PI / 2 - atan(2.0 * x / (b * b * a));
    }
    cout << theta * 180 / PI << "\n";
    return 0;
}