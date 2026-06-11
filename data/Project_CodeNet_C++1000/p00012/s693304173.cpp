#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

int main() {
    P a,b,c,d;
    while(cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y) {
        int x = ccw(a,b,d);
        int y = ccw(b,c,d);
        int z = ccw(c,a,d);
        // printf("%d %d %d\n", x, y, z);
        if(x == 1 && y == 1 && z == 1) cout << "YES" << endl;
        else if(x == -1 && y == -1 && z == -1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}