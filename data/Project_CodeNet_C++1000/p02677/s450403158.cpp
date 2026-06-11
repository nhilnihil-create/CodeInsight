#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main()
{
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    auto minAngle = [](int min) -> double {
        return M_PI * (min / 30.);
    };

    auto hourAngle = [](int hour, int min) -> double {
        return M_PI * (hour / 6. + min / 360.);
    };

    double hourX = A * sin(hourAngle(H, M));
    double hourY = A * cos(hourAngle(H, M));
    double minX = B * sin(minAngle(M));
    double minY = B * cos(minAngle(M));
    double disX = abs(hourX - minX);
    double disY = abs(hourY - minY);

    char out[100];
    snprintf(out, 100, "%20.20f", sqrt(disX * disX + disY * disY));
    cout << out << endl;

    return 0;
}