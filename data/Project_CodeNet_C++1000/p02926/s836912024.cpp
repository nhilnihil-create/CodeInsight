#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

typedef pair<int, int> pint;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front

#define MOD (1000 * 1000 * 1000 + 7)

double dot(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

#define M 1000

signed main() {
    int N;
    vector<int> xx, yy;

    cin >> N;
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        xx.pb(x);
        yy.pb(y);
    }

    double ans = 0;

    REP(i, M) {
        double rad = (double) i / M * M_PI * 2;
        double vec_x = cos(rad);
        double vec_y = sin(rad);
        double total_x = 0;
        double total_y = 0;

        REP(i, N) {
            if (dot(xx[i], yy[i], vec_x, vec_y) >= 0) {
                total_x += xx[i];
                total_y += yy[i];
            }
        }

        if (pow(total_x, 2) + pow(total_y, 2) > ans) {
            ans = pow(total_x, 2) + pow(total_y, 2);
        }
    }
    ans = sqrt(ans);

    cout << setprecision(12) << ans << endl;

    return 0;
}