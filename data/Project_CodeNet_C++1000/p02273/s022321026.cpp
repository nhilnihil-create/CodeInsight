#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

struct P {
    double x, y;
    P() { x = 0.0, y = 0.0; }
    P(double x, double y) : x(x), y(y) {}
};
P operator+(const P &p1, const P &p2) {
    return P(p1.x + p2.x, p1.y + p2.y);
}
P operator-(const P &p1, const P &p2) {
    return P(p1.x - p2.x, p1.y - p2.y);
}
P operator*(double k, const P &p) {
    return P(k * p.x, k * p.y);
}
P operator*(const P &p, double k) {
    return k * p;
}

//       p5
//       /\
// p1___/ \___p2
//    p3  p4
void KochCurve(P p1, P p2, int n)
{
    if (n == 0)
        return ;

    P p3 = 1.0 / 3.0 * (p2 - p1) + p1;
    P p4 = 2.0 / 3.0 * (p2 - p1) + p1;
    P tmp = p4 - p3;
    P p5;

    double theta = M_PI / 3.0;
    p5.x = cos(theta) * tmp.x - sin(theta) * tmp.y + p3.x;
    p5.y = sin(theta) * tmp.x + cos(theta) * tmp.y + p3.y;

    KochCurve(p1, p3, n - 1);
    printf("%.8f %.8f\n", p3.x, p3.y);
    KochCurve(p3, p5, n - 1);
    printf("%.8f %.8f\n", p5.x, p5.y);
    KochCurve(p5, p4, n - 1);
    printf("%.8f %.8f\n", p4.x, p4.y);
    KochCurve(p4, p2, n - 1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    printf("%.8f %.8f\n", 0.0, 0.0);
    KochCurve(P(0.0, 0.0), P(100.0, 0), n);
    printf("%.8f %.8f\n", 100.0, 0.0);

    return 0;
}