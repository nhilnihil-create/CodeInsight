#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
inline void print(Point a) { printf("%.8lf %.8lf\n", real(a), imag(a)); }
constexpr Point to_rotate() { return Point(cos(acos(-1.0) / 3.0), sin(acos(-1.0) / 3.0));}
void recursion(Point l, Point r, int depth) {
    if(depth == 0) return;
    Point base = (r - l) / 3.0;
    Point a(l + base), b(l + base * 2.0);
    Point c = to_rotate() * (b - a) + a;
    recursion(l, a, depth - 1);
    print(a);
    recursion(a, c, depth - 1);
    print(c);
    recursion(c, b, depth - 1);
    print(b);
    recursion(b, r, depth - 1);
}
int main() {
    int n;
    scanf("%d", &n);
    Point a(0.0, 0.0), b(100.0, 0.0);
    print(a);
    recursion(a, b, n);
    print(b);
    return 0;
}