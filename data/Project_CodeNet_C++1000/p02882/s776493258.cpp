#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;


ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const double PI=3.14159265358979323846;



int main(){
    int a, b;
    double x;
    scanf("%d%d%lf", &a, &b, &x);
    if(a * a * b / 2 > x) {
        double c = 2 * x / a / b;
        double res = atan(b / c) * 180 / PI;
        printf("%.10lf\n", res);
    } else {
        double c = 2 * (b - (x / a / a));
        double res = atan(c / a) * 180 / PI;
        printf("%.10lf\n", res);
    }
    return 0;
}