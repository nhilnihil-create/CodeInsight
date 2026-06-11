#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

const double PI = 3.1415926535853;

int main() {
    int a, b, h, m; cin >> a >> b >> h >> m;
    double ha = (h * 60 + m) / 720.0 * 360, ma = m * 6;
    double g = fabs(ha - ma);
    double x = cos(g / 180 * PI);
    printf("%.10lf\n", sqrt(a * a + b * b - 2 * a * b * x));
}