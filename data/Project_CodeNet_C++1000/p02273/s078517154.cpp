#include <iostream>
#include <cmath>

struct coordinate{
    double x;
    double y;
};

void koch(int depth, coordinate start, coordinate end);

int main() {
    int depth;
    coordinate start, end;
    start.x = 0.0;
    start.y = 0.0;
    end.x = 100.0;
    end.y = 0.0;

    std::cin >> depth;

    std::cout.precision(8);

    std::cout << std::fixed << start.x << " " << start.y << std::endl;
    koch(depth, start, end);
    std::cout << std::fixed << end.x << " " << end.y << std::endl;

    return 0;
}

void koch(int depth, coordinate start, coordinate end) {
    if (depth == 0) {
        return;
    }

    coordinate s, u, t;
    s.x = (2 * start.x + end.x) / 3;
    s.y = (2 * start.y + end.y) / 3;
    t.x = (start.x + 2 * end.x) / 3;
    t.y = (start.y + 2 * end.y) / 3;
    u.x = (t.x - s.x) / 2 - (t.y - s.y) * sqrt(3) / 2 + s.x;
    u.y = (t.x - s.x) * sqrt(3) / 2 + (t.y - s.y) / 2 + s.y;

    std::cout.precision(8);

    koch(depth - 1, start, s);

    std::cout << std::fixed << s.x << " " << s.y << std::endl;

    koch(depth - 1, s, u);

    std::cout << std::fixed << u.x << " " << u.y << std::endl;

    koch(depth - 1, u, t);

    std::cout << std::fixed << t.x << " " << t.y << std::endl;

    koch(depth - 1, t, end);
}
