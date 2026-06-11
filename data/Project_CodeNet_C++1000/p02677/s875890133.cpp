#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define begin begin()
#define end end()

void _main(){
    int a,b;
    int h,m;
    cin >> a >> b >> h >> m;
    double t = abs(h*30+m*0.5-m*6);
    double s = max(t,360-t)*M_PI/180;
    double c = sqrt(a*a+b*b-2*a*b*cos(s));
    cout << c << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    