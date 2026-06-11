#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int main()
{
    double a, b, x, ans;
    const double PI = acos(-1.0);
    cin >> a >> b >> x;

    x /= a;

    if (x > a * b / 2) {
        ans = atan2(2 * (a * b - x), a * a);
        ans = ans * 180 / PI;
    }
    else {
        ans = atan2(b * b, 2 * x);
        ans = ans * 180 /PI;
    }

    printf("%.8lf\n", ans);
    return 0;
}