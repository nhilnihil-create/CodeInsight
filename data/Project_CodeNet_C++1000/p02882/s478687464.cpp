#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

double a, b, x;
int main() {
    cin >> a >> b >> x;

    double area = x / a; 
    double radian = 0;
    if (2 * area >= a * b) {
        // 半分以上
        double tmp = 2 * (b - x / (a * a)); 
        radian = atan2(tmp, a);
    } else {
        // 半分未満
        double tmp = (2 * x) / (a * b);
        radian = atan2(b, tmp);
    }
    // radian = atan2(1, 1);
    double degree = radian * 180.0 / M_PI;

    printf("%.10f\n", degree);
}