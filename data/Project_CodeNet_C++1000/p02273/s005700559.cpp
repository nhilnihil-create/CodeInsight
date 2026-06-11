#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>
#include <iomanip>

const double rad60 = 60 * M_PI / 180;

void koch_curve(std::pair<double, double> p1, std::pair<double, double> p2, int n) {
    if (n == 0) return;
    
    std::pair<double, double> s, t, u;
    
    s.first = (2.0 * p1.first + 1.0 * p2.first) / 3.0;
    s.second = (2.0 * p1.second + 1.0 * p2.second) / 3.0;
    t.first = (1.0 * p1.first + 2.0 * p2.first) / 3.0;
    t.second = (1.0 * p1.second + 2.0 * p2.second) / 3.0;
    u.first = (t.first - s.first) * std::cos(rad60) - (t.second - s.second) * std::sin(rad60) + s.first;
    u.second = (t.first - s.first) * std::sin(rad60) + (t.second - s.second) * std::cos(rad60) + s.second;
    
    koch_curve(p1, s, n-1);
    std::cout << s.first << " " << s.second << std::endl;
    koch_curve(s, u, n-1);
    std::cout << u.first << " " << u.second << std::endl;
    koch_curve(u, t, n-1);
    std::cout << t.first << " " << t.second << std::endl;
    koch_curve(t, p2, n-1);
}

int main() {
    std::pair<double, double> p1, p2;
    // starting point
    p1.first = 0.0f; p1.second = 0.0f;
    // ending point
    p2.first = 100.0f; p2.second = 0.0f;
    
    std::cout << std::fixed << std::setprecision(8);
    
    int n;
    std::cin >> n;
    
    std::cout << p1.first << " " << p1.second << std::endl;
    koch_curve(p1, p2, n);
    std::cout << p2.first << " " << p2.second << std::endl;
}
