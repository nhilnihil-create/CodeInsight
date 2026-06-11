#include <iostream>
#include <iomanip>
#include <cmath>

struct point {
    double x, y;
};

point point1 = {0.0f, 0.0f}, point2 = {100.0f, 0.0f};
const long double pi = 3.141592653589793f;

void KochCurve(int depth, point point1, point point2) {
    if (depth==0) return;

    point A, B, C, dif;
    dif.x = point2.x - point1.x;
    dif.y = point2.y - point1.y;
    
    /*
                  A
                 /\
    point1 _____/  \_____point2
               B   C
    */
    
    /*
    When (x, y) -> (x', y'),
    x' = x*cos - y*sin
    y' = x*sin + y*cos
    */

    A.x = (dif.x*std::cos(pi/3) - dif.y*std::sin(pi/3))/3 + dif.x/3 + point1.x;
    A.y = (dif.x*std::sin(pi/3) + dif.y*std::cos(pi/3))/3 + dif.y/3 + point1.y;
    
    B.x = dif.x/3 + point1.x;
    B.y = dif.y/3 + point1.y;

    C.x = dif.x*2/3 + point1.x;
    C.y = dif.y*2/3 + point1.y;

    KochCurve(depth-1, point1, B);
    std::cout << std::fixed << std::setprecision(8) << B.x << " " << B.y << std::endl;
    KochCurve(depth-1, B, A);
    std::cout << std::fixed << std::setprecision(8) << A.x << " " << A.y << std::endl;
    KochCurve(depth-1, A, C);
    std::cout << std::fixed << std::setprecision(8) << C.x << " " << C.y << std::endl;
    KochCurve(depth-1, C, point2);
}

int main() {
    int depth;
    std::cin >> depth;

    std::cout << point1.x << " " << point1.y << std::endl;
    KochCurve(depth, point1, point2);
    std::cout << point2.x << " " << point2.y << std::endl;
}
