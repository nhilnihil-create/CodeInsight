#include <iostream>
#include <cstdio>
#include <complex>

using namespace std;
typedef long long ll;

typedef double R;
typedef complex<R> P;

const R EPS = 1e-10;
const R PI = acos(-1);
int sgn(R a) {
    if (a < -EPS) return -1;
    if (a > EPS) return 1;
    return 0;
}


bool near(P a, P b) {
    return !sgn(abs(a-b));
}

double cross(const P &a, const P &b) { return imag(conj(a)*b); }
double dot(const P &a, const P &b) { return real(conj(a)*b); }

P p[4];
void solve() {
    p[0] -= p[3];
    p[1] -= p[3];
    p[2] -= p[3];
    int u = 0;
    for (int i = 0; i < 3; i++) {
        P p1 = p[i], p2 = p[(i+1)%3];
        if (p1.imag() > p2.imag()) swap(p1, p2);
        if (p1.imag() > 0 || p2.imag() <= 0) continue;
        if (cross(p1, p2) < 0) continue;
        u++;
    }
    if (u == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    while (true) {
        for (int i = 0; i < 4; i++) {
            R x, y;
            cin >> x >> y;
            p[i] = P(x, y);
        }
        if (cin.eof()) break;
        solve();
    }
    return 0;
}