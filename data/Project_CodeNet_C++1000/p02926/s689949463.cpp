#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define PI 3.14159265358979
#define int long long

double inner_product1(double x1, double y1, double x2, double y2) {
    return (x1 * x2 + y1 * y2);
}


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int x[110], y[110];
    rep(i, N) cin >> x[i] >> y[i];
    double ans = 0.0;
    rep(i, 200000) {
        int X = 0, Y = 0;
        rep(j, N) {
            double theta = PI/(i/100000.0);
            double xx = cos(theta);
            double yy = sin(theta);
            if (inner_product1(xx, yy, x[j], y[j]) >= 0) {
                X += x[j];
                Y += y[j];
            }
        }
        ans = max(ans, sqrt(X * X + Y * Y));
    }
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
