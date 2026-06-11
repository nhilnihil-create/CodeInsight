#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    double pi = 3.14159265358979323;
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    h += m / 60.0;
    h = pi / 2.0 - (h / 12.0) * 2 * pi;
    m = pi / 2.0 - (m / 60.0) * 2 * pi;
    double ax, ay, bx, by;
    ax = sin(h) * a;
    ay = cos(h) * a;
    bx = sin(m) * b;
    by = cos(m) * b;
    cout << fixed << setprecision(10) << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) << endl;
}