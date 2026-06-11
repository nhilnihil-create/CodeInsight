#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
const int INF = 0x3f3f3f3f;
const int maxn = 1100000;

void run_case()
{
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double angle1 = h * 30.0 + m * 0.5;
    double angle2 = m * 6.0;
    double angle = min(abs(angle1 - angle2), 360 - abs(angle1 - angle2));
    //DBG(angle);
    double t = angle * PI * 1.0 / 180;
    //DBG(cos(t));
    double c = sqrt(a * a * 1.0 + b * b * 1.0 - 2 * a * b * cos(t));
    cout << c << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(15);
    run_case();
    cout.flush();
    return 0;
}