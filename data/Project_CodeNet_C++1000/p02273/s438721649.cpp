#include <stdio.h>


class Point {
public:
    float x;
    float y;
    void print() {
        printf("%.6f %.6f\n", x, y);
    }
};

//print depth-d koch except for p1,p2
void koch(int d, Point p1, Point p2) {
    if (d == 0) {
        return;
    }
    Point s,u,t;
    //(1/3)(p2-p1)=s-p1
    s.x=(p2.x+2*p1.x)/3;
    s.y=(p2.y+2*p1.y)/3;
    //(2/3)(p2-p1)=t-p1
    t.x=(2*p2.x+p1.x)/3;
    t.y=(2*p2.y+p1.y)/3;
    //u-s=R(t-s),where R is rotation matrix
    u.x=s.x+0.5*(t.x-s.x)-0.866025*(t.y-s.y);
    u.y=s.y+0.866025*(t.x-s.x)+0.5*(t.y-s.y);

    koch(d-1,p1,s);
    s.print();
    koch(d-1,s,u);
    u.print();
    koch(d-1,u,t);
    t.print();
koch(d-1,t,p2);
}

int main() {
    int n;
    scanf("%d",&n);
    Point p1,p2;
    p1.x=0;
    p1.y=0;
    p2.x=100;
    p2.y=0;
    p1.print();
    koch(n,p1,p2);
    p2.print();
    return 0;
}

