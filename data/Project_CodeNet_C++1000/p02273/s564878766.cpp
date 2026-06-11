#include <iostream>
#include <utility>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

pair<double, double> div(pair<double, double> p1, pair<double, double> p2, int m, int n)
{
    double x = n * p1.first + m * p2.first;
    x /= double(n + m);
    double y = n * p1.second + m * p2.second;
    y /= double(n + m);
    return make_pair(x, y);
}

pair<double, double> rotate(pair<double, double> p1, pair<double, double> p2, double theta)
{
    double x = (p2.first - p1.first) * cos(theta) - (p2.second - p1.second) * sin(theta);
    double y = (p2.first - p1.first) * sin(theta) + (p2.second - p1.second) * cos(theta);
    return make_pair(p1.first + x, p1.second + y);
}

void kochCurve(pair<double, double> p1, pair<double, double> p2, int n, vector<pair<double, double>> &stock)
{
    if (n == 0)
    {
        return;
    }
    pair<double, double> s, u, t;
    s = div(p1, p2, 1, 2);
    t = div(p1, p2, 2, 1);
    u = rotate(s, t, M_PI / 3.);
    kochCurve(p1, s, n - 1, stock);
    stock.push_back(s);
    kochCurve(s, u, n - 1, stock);
    stock.push_back(u);
    kochCurve(u, t, n - 1, stock);
    stock.push_back(t);
    kochCurve(t, p2, n - 1, stock);
}

int main()
{
    vector<pair<double, double>> koch(0);
    int n;
    cin >> n;
    koch.push_back(make_pair(0., 0.));
    kochCurve(make_pair(0., 0.), make_pair(100., 0.), n, koch);
    koch.push_back(make_pair(100., 0.));

    for (auto e : koch)
    {
        cout << fixed << setprecision(10) << e.first
             << " " << fixed << setprecision(10) << e.second << endl;
    }
    return 0;
}
