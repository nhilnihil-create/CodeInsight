#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

const pair<double, double> operator+(const pair<double, double> p1, const pair<double, double> p2) {
    pair<double, double> q;
    q.first = p1.first + p2.first;
    q.second = p1.second + p2.second;
    return q;
}
const pair<double, double> operator-(const pair<double, double> p1, const pair<double, double> p2) {
    pair<double, double> q;
    q.first = p1.first - p2.first;
    q.second = p1.second - p2.second;
    return q;
}
const pair<double, double> operator*(const pair<double, double> p, const double k) {
    pair<double, double> q;
    q.first = p.first * k;
    q.second = p.second * k;
    return q;
}
const pair<double, double> operator/(const pair<double, double> p, const double k) {
    pair<double, double> q;
    q.first = p.first / k;
    q.second = p.second / k;
    return q;
}

void koch_curve(int depth, pair<double, double> p1, pair<double, double> p2) {
    if(depth == 0) return;

    pair<double, double> q1, q2, q3, rot;
    q1 = (p1 * 2 + p2) / 3;
    q3 = (p1 + p2 * 2) / 3;
    rot.first = -((q3 - q1) * sqrt(3) / 2).second;
    rot.second = ((q3 - q1) * sqrt(3) / 2).first;
    q2 = (q1 + q3) / 2 + rot;

    koch_curve(depth - 1, p1, q1);
    printf("%.8lf %.8lf\n", q1.first, q1.second);
    koch_curve(depth - 1, q1, q2);
    printf("%.8lf %.8lf\n", q2.first, q2.second);
    koch_curve(depth - 1, q2, q3);
    printf("%.8lf %.8lf\n", q3.first, q3.second);
    koch_curve(depth - 1, q3, p2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pair<double, double> p1(0, 0), p2(100, 0);
    printf("%.8lf %.8lf\n", p1.first, p1.second);
    koch_curve(n, p1, p2);
    printf("%.8lf %.8lf\n", p2.first, p2.second);

    return 0;
}
