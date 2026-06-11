#include <iostream>
#include <complex>

using namespace std;

typedef struct{
    double x;
    double y;
}Point;

void koch(int n, Point p1, Point p2){
    if(n == 0) return;

    Point s, t, u;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;
    u.x = (t.x - s.x) / 2 - (t.y - s.y) * sqrt(3) / 2 + s.x;
    u.y = (t.x - s.x) * sqrt(3) / 2 + (t.y - s.y) / 2 + s.y;

    koch(n-1, p1, s);
    cout << s.x << " " << s.y << endl;
    koch(n-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n-1, t, p2);
}

int main(){
    int n;
    cin >> n;

    Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100;
    p2.y = 0.0;

    cout << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << p2.x << " " << p2.y << endl;

    return 0;
}
