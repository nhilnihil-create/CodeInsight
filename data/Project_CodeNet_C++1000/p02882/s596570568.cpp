#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    double a, b, x; cin >> a >> b >> x;

    double s = x / a;
    double rad;
    if(s >= a * b / 2){
        double h = (a * b - s) * 2 / a;
        rad = atan2(h, a);
    }else{
        double w = s * 2 / b;
        rad = atan2(b, w);
    }
    double PI = acos(-1);
    double deg = rad / (2 * PI) * 360;
    printf("%.10f", deg);

    return 0;
}
