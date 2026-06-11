#include <bits/stdc++.h>
using namespace std;

#define _USES_MATH_DEFINES

#define x first
#define y second

int cmp(pair<int, int> a, pair<int, int> b) {
    auto f = [](long double Rad) -> long double { 
        if( Rad < 0 ) Rad += (2*M_PI);
        return Rad;
    };
    return f(atan2l(a.y, a.x)) < f(atan2l(b.y, b.x));
}

int more_than_rad(pair<int, int> a, pair<int, int> b) {
    long double ang = atan2l( a.y - b.y, a.x - b.x );
    if(ang < 0) ang += (2*M_PI);
    //
    return (ang > M_PI);
}

long double eulDist(long long x, long long y) {
    return sqrtl( x*x + y*y );
}

int main() {
    // pair<int, int> a = {0, 0}, b = {5, 5};
    // cout << fixed << setprecision(5) << atan2l( a.y - b.y, a.x - b.x ) << endl;
    // return 0;
    //
    int n; cin >> n;
    vector< pair<int, int> > P (n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    //
    sort(P.begin(), P.end(), cmp);
    // vector< pair<int, int> > sumV = {{0, 0}};
    // for(auto &p : P) {
    //     pair<int, int> pp = *(sumV.rbegin());
    //     sumV.push_back( {pp.x + p.x, pp.y + p.y} );
    // }
    //

    // for(int i = 0; i < n; i++) {
    //     cerr << "Point " << i << " : " << P[i].x << " " << P[i].y << endl;
    // }
    // return 0;

    int L = 0, R = 0;
    long double maxR = 0.0;
    while(L < n) {
        int subx = P[L].x, suby = P[L].y;
        maxR = max(maxR, eulDist(subx, suby));
        // cerr << "@ L = " << L << endl;
        //
        R = (L + 1) % n;
        while( L != R  ) {
            // cerr << "@@ R = " << R << endl;
            // cerr << "@@ maxR = " << maxR << endl;
            subx += P[R].x;
            suby += P[R].y;
            maxR = max(maxR, eulDist(subx, suby));
            R = (R + 1) % n;
            if(L == R) break;
        }
        //
        L++;
    }
    //
    cout << fixed << setprecision(50) << maxR;
}
