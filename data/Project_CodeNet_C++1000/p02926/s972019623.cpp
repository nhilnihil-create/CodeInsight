#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 400010;
const double pi = acos(-1.0);

struct vec
{
    int x, y;
    double angle;
};
bool cmp(vec w, vec v){ return w.angle < v.angle; }

vec a[N];
ll ans = 0, n, x = 0, y = 0;
int pointer = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].angle = atan2(a[i].y, a[i].x);
    }
    a[0].x = a[0].y = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
        a[i + n].angle = a[i].angle + pi * 2;
    }
    for (int i = 1; i <= n; i++)
    {
        x -= a[i - 1].x; y -= a[i - 1].y;
        ans = max(ans, 1LL * x * x + 1LL * y * y);
        while (pointer + 1 - i + 1 <= n && pointer + 1 <= 2 * n && a[pointer + 1].angle - a[i].angle <= pi)
        {
            pointer ++;
            x += a[pointer].x;
            y += a[pointer].y;
            ans = max(ans, 1LL * x * x + 1LL * y * y);
        }
    }
    cout << fixed << setprecision(12) << (double)sqrt(ans) << endl;
    return 0;
}