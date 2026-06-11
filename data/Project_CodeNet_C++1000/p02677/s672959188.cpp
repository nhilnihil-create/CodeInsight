#include <bits/stdc++.h>
using namespace std;

int main() {
    static const double PI = 3.14159265358979323846;
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    auto rad = PI * 2 * (h / 12.0 + (m / 60.0) / 12.0 - m / 60.0);
    auto rsq = (double) (a * a + b * b) - (double) (2 * a * b) * cos(rad);
    printf("%20.20f\n", sqrt(rsq));
}