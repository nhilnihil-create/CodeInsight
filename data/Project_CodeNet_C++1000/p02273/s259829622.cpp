#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct point {
    double x, y;
};

void koch (int d, point p1, point p2) {
    if (d == 0) return;
    point s, u, t;
    s.x = (p2.x - p1.x) / 3 + p1.x;
    s.y = (p2.y - p1.y) / 3 + p1.y;
    t.x = p2.x - (p2.x - p1.x) / 3;
    t.y = p2.y - (p2.y - p1.y) / 3;
    u.x = (t.x - s.x) * cos (pi / 3) - (t.y - s.y) * sin (pi / 3) + s.x;
    u.y = (t.x - s.x) * sin (pi / 3) + (t.y - s.y) * cos (pi / 3) + s.y;
    koch (d - 1, p1, s);
    cout << fixed << setprecision (15) << s.x << " " << fixed
         << setprecision (15) << s.y << "\n";
    koch (d - 1, s, u);
    cout << fixed << setprecision (15) << u.x << " " << fixed
         << setprecision (15) << u.y << "\n";
    koch (d - 1, u, t);
    cout << fixed << setprecision (15) << t.x << " " << fixed
         << setprecision (15) << t.y << "\n";
    koch (d - 1, t, p2);
}

int main() {
    point a, b;
    int n;
    cin >> n;
    a.x = 0, a.y = 0;
    b.x = 100, b.y = 0;

    cout << fixed << setprecision (15) << a.x << " " << fixed
         << setprecision (15) << a.y << "\n";
    koch (n, a, b);
    cout << fixed << setprecision (15) << b.x << " " << fixed
         << setprecision (15) << b.y << "\n";
}
