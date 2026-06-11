#include <iostream>
#include <cmath>
#include <iomanip>

class Point{
public:
    Point( double x, double y ) : x(x), y(y){}
    double x;
    double y;
    void Print(){
        std::cout << x << " " << y << "\n";
    }
};

void Koch( int n, const Point& p1, const Point& p2 ){
    if( n ){
        Point s( ( 2*p1.x + p2.x ) / 3, ( 2*p1.y + p2.y ) / 3 );
        Point t( ( p1.x + 2*p2.x ) / 3, ( p1.y + 2*p2.y ) / 3 );
        Point u( ( t.x - s.x )*cos( M_PI/3 ) - ( t.y - s.y )*sin( M_PI/3 ) + s.x,
                 ( t.x - s.x )*sin( M_PI/3 ) + ( t.y - s.y )*cos( M_PI/3 ) + s.y );
        
        // if( n == 1 ){
        //     s.x /= 3.0;
        //     s.y /= 3.0;
        //     t.x /= 3.0;
        //     t.y /= 3.0;
        //     u.x /= 3.0;
        //     u.y /= 3.0;
        // }

        Koch( n-1, p1, s );
        s.Print();
        Koch( n-1, s, u );
        u.Print();
        Koch( n-1, u, t );
        t.Print();
        Koch( n-1, t, p2 );
    }
    return;
}

int main(){
    int n;
    std::cin.tie(0);
    std::cin >> n;
    Point p1 = Point( 0.0, 0.0 );
    Point p2 = Point( 100.0, 0.0 );
    std::cout << std::fixed << std::setprecision(8);
    p1.Print();
    Koch( n, p1, p2 );
    p2.Print();
}
