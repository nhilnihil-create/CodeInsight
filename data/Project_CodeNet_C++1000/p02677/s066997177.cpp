#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    long double a,b,h,m;
    
    cin >> a >> b >> h >> m;
    long double s = (h * 60 + m) / 720 * 2 * acos(-1);
    long double l = m / 60 * 2 * acos(-1);
    long double angle = abs(l - s);
    printf("%20.20Lf\n",sqrt(a * a + b * b - 2 * a * b * cos(angle)));
}
