#include<iostream>
#include<cmath>
using namespace std;

struct Point{
    double x;
    double y;
    Point(double x_in, double y_in){
        x = x_in;
        y = y_in;
    }
    Point(){}
};

struct Segment{
    Point p1;
    Point p2;
    Segment(const Point& p1_in, const Point& p2_in){
        p1 = p1_in;
        p2 = p2_in;
    }
};

Point calc_s(const Segment& S){
    double x = (2 * S.p1.x + S.p2.x) / 3.0;
    double y = (2 * S.p1.y + S.p2.y) / 3.0;
    Point P(x, y);
    return P;
}

Point calc_t(const Segment& S){
    double x = (S.p1.x + 2 * S.p2.x) / 3.0;
    double y = (S.p1.y + 2 * S.p2.y) / 3.0;
    Point P(x, y);
    return P;
}

Point calc_u(const Point& s, const Point& t){
    double distance = sqrt((s.x - t.x) * (s.x - t.x)
                         + (s.y - t.y) * (s.y - t.y));
    double cos_ = (t.x - s.x) / distance;
    double sin_ = (t.y - s.y) / distance;
    double x_tmp1 = distance / 2.0;
    double y_tmp1 = x_tmp1 * sqrt(3.0);

    double x_tmp2 = cos_ * x_tmp1 - sin_ * y_tmp1;
    double y_tmp2 = sin_ * x_tmp1 + cos_ * y_tmp1;

    double x_ = x_tmp2 + s.x;
    double y_ = y_tmp2 + s.y;
    Point ret(x_, y_);
    return ret;
}

void Koch(const Segment& Seg, int n){
    if (n == 0) return;
    Point s = calc_s(Seg);
    Point t = calc_t(Seg);
    Point u = calc_u(s, t);
    Segment Seg1(Seg.p1, s);
    Koch(Seg1, n - 1);
    cout << s.x << " " << s.y << endl;
    Segment Seg2(s, u);
    Koch(Seg2, n - 1);
    cout << u.x << " " << u.y << endl;
    Segment Seg3(u, t);
    Koch(Seg3, n - 1);
    cout << t.x << " " << t.y << endl;
    Segment Seg4(t, Seg.p2);
    Koch(Seg4, n - 1);
}


int main(){
    int n;
    cin >> n;

    Point p1(  0.0, 0.0);
    Point p2(100.0, 0.0);
    Segment Seg(p1, p2);
    cout << Seg.p1.x << " " << Seg.p1.y << endl;
    Koch(Seg, n);
    cout << Seg.p2.x << " " << Seg.p2.y << endl;

    return 0;
}