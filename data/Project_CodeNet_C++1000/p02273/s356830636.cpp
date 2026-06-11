#include <bits/stdc++.h>
#define SIZE 10000
using namespace std;
vector<pair<double, double> > vertex;
void koch_curve(const pair<double, double> &p1, const pair<double, double> &p2, int n)
{
    if (n == 0)
    {
        return;
    }
    double ax = p1.first * 2 / 3 + p2.first / 3, ay = p1.second * 2 / 3 + p2.second / 3;
    double bx = p1.first / 3 + p2.first * 2 / 3, by = p1.second / 3 + p2.second * 2 / 3;
    double x = bx - ax, y = by - ay;
    double cx = ax + x * cos(M_PI / 3) - y * sin(M_PI / 3), cy = ay + x * sin(M_PI / 3) + y * cos(M_PI / 3);
    pair<double, double> a1 = make_pair(ax, ay), a2 = make_pair(cx, cy), a3 = make_pair(bx, by);
    koch_curve(p1, a1, n - 1);
    vertex.push_back(a1);
    koch_curve(a1, a2, n - 1);
    vertex.push_back(a2);
    koch_curve(a2, a3, n - 1);
    vertex.push_back(a3);
    koch_curve(a3, p2, n - 1);
}
int main()
{
    int n;
    cin >> n;
    vertex.push_back(make_pair(0, 0));
    koch_curve(make_pair(0, 0), make_pair(100, 0), n);
    vertex.push_back(make_pair(100, 0));
    for (int i = 0; i < vertex.size(); ++i)
        printf("%.8f %.8f\n", vertex[i].first, vertex[i].second);
}
