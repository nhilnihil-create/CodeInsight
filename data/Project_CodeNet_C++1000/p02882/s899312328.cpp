#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int a, b, x;
    cin >> a >> b >> x;
    double theta;
    if(x <= (double) (a*a*b*0.5)){
        theta = atan2((double) a * b * b, 2 * x);
    } else {
        theta = atan2((double) 2 * (a*a*b - x), a*a*a);
    }

    cout << fixed << setprecision(10) << theta / M_PI * 180 << endl;
    return 0;
}
