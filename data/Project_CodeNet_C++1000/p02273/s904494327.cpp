#include <cmath>
#include <iostream>
#include <utility>
#include <iomanip>
#include <string>

void print(const std::pair<double, double>& p)
{
    std::cout 
        << p.first
        << " "
        << p.second << std::endl;
    return;
}

void create_koch(
    const std::pair<double, double>& l,
    const std::pair<double, double>& r,
    const int depth)
{
    if (depth == 0) {
        print(l);
        return;
    }
    const auto p0 = std::make_pair(
        (l.first * 2 + r.first) / 3.0,
        (l.second * 2 + r.second) / 3.0);
    const auto p2 = std::make_pair(
        (l.first + r.first * 2) / 3.0,
        (l.second + r.second * 2) / 3.0);
    const auto p0top2 = std::make_pair(
        p2.first - p0.first,
        p2.second - p0.second);
    const double a[2][2]
        = { { 0.5, -std::sqrt(3) * 0.5} ,
        { std::sqrt(3) * 0.5, 0.5 } };
    const auto p1 = std::make_pair(
        p0.first + a[0][0] * p0top2.first + a[0][1] * p0top2.second,
        p0.second + a[1][0] * p0top2.first + a[1][1] * p0top2.second);
    create_koch(l, p0, depth - 1);
    create_koch(p0, p1, depth - 1);
    create_koch(p1, p2, depth - 1);
    create_koch(p2, r, depth - 1);

    return;
}

int main()
{
    int n;
    {
        std::string buf;
        std::getline(std::cin, buf);
        n = std::stoi(buf);
    }
    const auto l = std::make_pair(0, 0);
    const auto r = std::make_pair(100, 0);
    create_koch(l, r, n);
    print(r);
    return 0;
}