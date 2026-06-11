#include <iostream>
#include <cmath>
#include <iomanip>

struct Point{
    double x;
    double y;
    void print();
};

void koch(int n,Point p1,Point p2){
    if(n==0){
        return;
    }
    Point s,t,u;
    s.x = (2*p1.x + 1*p2.x) / 3.0;
    s.y = (2*p1.y + 1*p2.y) / 3.0;
    t.x = (1*p1.x + 2*p2.x) / 3.0;
    t.y = (1*p1.y + 2*p2.y) / 3.0;
    u.x = (t.x - s.x) * (1.0/ 2.0) - (t.y - s.y) * (sqrt(3.0) / 2.0) + s.x;
    u.y = (t.x - s.x) * (sqrt(3.0) / 2.0) + (t.y - s.y) *(1.0 / 2.0) + s.y;
    koch(n-1,p1,s);
    s.print();
    koch(n-1,s,u);
    u.print();
    koch(n-1,u,t);
    t.print();
    koch(n-1,t,p2);
}

int main(){
    Point p1,p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    int n;
    std::cin >> n;
    p1.print();
    koch(n,p1,p2);
    p2.print();
    return 0;
}

void Point::print(){
    std::cout << std::fixed;
    std::cout << std::setprecision(8) << x << " ";
    std::cout << std::setprecision(8) << y <<"\n";
}
