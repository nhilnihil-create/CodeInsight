#include<iostream>
#include<cmath>
#include<iomanip>

#define PI 3.14159265358979323846264338

//鈍角鋭角で鋭角じゃないとダメ
int main(){
    int a = 0;
    int b = 0;
    int h = 0;
    int m = 0;

    std::cin >> a >> b >> h >> m;

    double h_angle = 30 * h + 0.5 * m;
    double m_angle = 6 * m;
    double angle = std::max(std::abs(h_angle - m_angle), 360 - std::abs(h_angle - m_angle));

    double c = std::sqrt(a * a + b * b - 2 * a * b * std::cos(angle * PI / 180));

    std::cout << std::fixed << std::setprecision(20) << c << std::endl;

    return 0;
}