#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double len(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double area(Point *points) {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[0]);
    double s = (a + b + c) / 2;
    return sqrt(s*(s - a)*(s - b)*(s - c));
}

int is_in(Point *points, Point search) {
    double src = area(points);
    double a, b, c;
    
    swap(points[0], search);
    a = area(points);
    swap(points[0], search);

    swap(points[1], search);
    b = area(points);
    swap(points[1], search);

    swap(points[2], search);
    c = area(points);
    swap(points[2], search);

    if (src - 1e-5 < a + b + c && a + b + c < src + 1e-5) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    while (1) {
        Point points[3];
        Point search;

        for (int i = 0; i < 3; i++) {
            if (!(cin >> points[i].x >> points[i].y)) {
                return 0;
            }
        }
        cin >> search.x >> search.y;
    
        if (is_in(points, search) == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}