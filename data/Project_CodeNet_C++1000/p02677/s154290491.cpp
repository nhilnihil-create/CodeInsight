#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

int main() {
    double a, b, h , m; cin >> a >> b >> h >> m;
    h = h * 60;
    double angle_h = (h + m) * 0.5;
    double angle = angle_h-m*6;
    if(angle > 180) angle = 180 - (angle-180);
    printf("%.10lf", pow(a*a + b*b - 2*a*b*cos(angle * 3.1415926535897932384/180),0.5));
    return 0;
}