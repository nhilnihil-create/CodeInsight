#include<iostream>
using namespace std;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans1 = h * w / 2;
    int ans2 = 0;
    if (x == w / 2 & y == h / 2) ans2 = 1;
    cout << ans1 << ' ' << ans2 << endl;
}