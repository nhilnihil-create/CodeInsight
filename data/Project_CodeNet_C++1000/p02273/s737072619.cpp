#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define PI 3.14159265358979323846
struct Point{ double x, y;};

double kock(int n, Point p1, Point p2){
    if(n == 0) return 0;

    double rad = PI * 60.0 / 180.0;
    Point s, t, u;

    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    
    u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
    u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;

    kock(n-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    kock(n-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    kock(n-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    kock(n-1, t, p2);
}


int main(){

    int n; cin >> n;
    Point a = {0.0, 0.0}, b = {100.0, 0.0};
    printf("%.8f %.8f\n", a.x, a.y);
    kock(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}