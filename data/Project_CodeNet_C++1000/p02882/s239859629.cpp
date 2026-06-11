#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

double a, b, x;

double binary_search(double, double);
bool isOK(double);

int main() {
    cin >> a >> b >> x;
    double theta = binary_search(0, 90);
    printf("%.7f\n", theta);
    return 0;
}

double binary_search(double ok, double ng) {
    const double EPS = 1e-8;
    while (abs(ok - ng) > EPS) {
        double mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

bool isOK(double theta) {
    double theta_rad = theta * M_PI / 180;
    double v;
    if (a * sin(theta_rad) < b * cos(theta_rad)) v = a * a * b - 0.5 * a * a * a * tan(theta_rad);
    else v = 0.5 * b * b * a / tan(theta_rad);
    return x <= v;
}