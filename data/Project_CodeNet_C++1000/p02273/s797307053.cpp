#include <iostream>
#include <cstdio>
#include <cmath>

const double PI = 3.14159265;

struct Point {
    double x, y;
};

// 回転行列を掛け合わせる関数
void Rotation(const Point& s, const Point& t, Point& u) {
    double params = 60.0;
    double rad = params * PI / 180.0;
    double cos60 = cos(rad);
    double sin60 = sin(rad);

    u.x = cos60 * (t.x - s.x) - sin60 * (t.y - s.y) + s.x;
    u.y = sin60 * (t.x - s.x) + cos60 * (t.y - s.y) + s.y;
}

void KochCurve(const int n, Point left, Point right) {
    if(n != 0){
        // 多分ここで再帰
        Point s;
        Point t;
        Point u;

        // ベクトルで座標を計算する
        s.x = (2.0 * left.x + 1.0 * right.x) / 3.0;
        s.y = (2.0 * left.y + 1.0 * right.y) / 3.0;
        t.x = (2.0 * right.x + 1.0 * left.x) / 3.0;
        t.y = (2.0 * right.y + 1.0 * left.y) / 3.0;

        Rotation(s, t, u);

        KochCurve(n-1, left, s);
        printf("%08f %08f\n", s.x, s.y);
        KochCurve(n-1, s, u);
        printf("%08f %08f\n", u.x, u.y);
        KochCurve(n-1, u, t);
        printf("%08f %08f\n", t.x, t.y);
        KochCurve(n-1, t, right);

    }
}

int main() {
    int n;
    std::cin >> n;

    Point left;
    left.x = 0;
    left.y = 0;

    Point right;
    right.x = 100;
    right.y = 0;

    printf("%08f %08f\n", left.x, left.y);
    KochCurve(n, left, right);
    printf("%08f %08f\n", right.x, right.y);
}
