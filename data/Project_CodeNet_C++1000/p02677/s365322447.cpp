#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

double PI = acos(-1);

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    int time = 60 * H + M;
    // 時針の角度は、time / (6 * 60) * PI;
    // 分針の角度は、(time % 60) / 30 * PI;
    double theta1 = time * PI / (6 * 60);
    double theta2 = (time%60) * PI / 30;
    double x = (A * cos(theta1) - B * cos(theta2));
    double y = (A * sin(theta1) - B * sin(theta2));
    double ans = sqrt(x*x + y*y);
    printf("%.10f\n", ans);
    return 0;
}