#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int A, B, H, M;
    std::cin >> A >> B >> H >> M;
    long double pi = 3.141592653589793238462643383L;
    long double h_angle = pi * (long double)H / 6.0L + pi * (long double)M / 360.0L;
    long double m_angle = pi * (long double)M / 30.0L;
    long double diff_angle = h_angle - m_angle;
    long double m_x = (long double)A;
    long double m_y = 0.0L;
    long double h_x = (long double)B * std::cos(diff_angle);
    long double h_y = (long double)B * std::sin(diff_angle);
    /*
    long double m_x = (long double)A * std::cos(m_angle);
    long double m_y = (long double)A * std::sin(m_angle);
    long double h_x = (long double)B * std::cos(h_angle);
    long double h_y = (long double)B * std::sin(h_angle); */
    long double result = std::sqrt((m_x - h_x) * (m_x - h_x) + (m_y - h_y) * (m_y - h_y));
    std::cout << std::fixed << std::setprecision(15) << result << std::endl;
}