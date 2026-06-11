#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    ld a, b, h, m;
    cin >> a >> b >> h >> m;
    ld ra = h * (2 * M_PIl) / 12 + m * 2 * M_PIl / 12 / 60;
    ld rb = m * 2 * M_PIl / 60;

    ld xa = a * cosl(ra);
    ld ya = a * sinl(ra);
    ld xb = b * cosl(rb);
    ld yb = b * sinl(rb);

    ld ans = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    ans = sqrtl(ans);
    printf("%.20Lf\n", ans);

    return 0;
}