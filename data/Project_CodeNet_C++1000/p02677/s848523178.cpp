#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define PI acos(-1.0)

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    double a,b,h,m;
    cin >> a >> b >> h >> m;

    h = h * 30 + m * 0.5;
    m = m * 6;

    double diff = abs(m - h);
    double x = (PI * diff) / 180;
    double res = sqrt(a * a + b * b - 2 * a * b * (cos(x)));

    cout << setprecision(12) << fixed << res << endl;

}