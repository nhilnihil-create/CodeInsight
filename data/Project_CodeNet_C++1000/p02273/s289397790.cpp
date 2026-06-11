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
    double x = (t.x - s.x) * cos(M_PI / 3.0) -
               (t.y - s.y) * sin(M_PI / 3.0) + s.x;
    double y = (t.x - s.x) * sin(M_PI / 3.0) +
               (t.y - s.y) * cos(M_PI / 3.0) + s.y;
    Point ret(x, y);
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