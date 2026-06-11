#include <iostream>

class Vec {
private:
    double m_x;
    double m_y;

public:
    Vec(double x, double y)
        : m_x(x), m_y(y) {}

    double x() const { return m_x; }
    double y() const { return m_y; }

    double operator*(Vec& vec)
    {
        return (m_x * vec.y() - m_y * vec.x());
    }
};

int sign(double x);

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double xp, yp;

    while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp) {
        Vec vec12(x2 - x1, y2 - y1);
        Vec vec1p(xp - x1, yp - y1);
        Vec vec23(x3 - x2, y3 - y2);
        Vec vec2p(xp - x2, yp - y2);
        Vec vec31(x1 - x3, y1 - y3);
        Vec vec3p(xp - x3, yp - y3);

        double cross01 = vec12 * vec1p;
        double cross02 = vec23 * vec2p;
        double cross03 = vec31 * vec3p;
        int judge = sign(cross01) + sign(cross02) + sign(cross03);

        if (judge == 1 + 1 + 1 || judge == -1 - 1 - 1) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

int sign(double x)
{
    return ((x >= 0)? 1: (-1));
}