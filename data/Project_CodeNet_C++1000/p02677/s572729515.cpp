#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

long double A,B,H,M;

void input(){
    cin >> A >> B >> H >> M;
}

void solve(){
    //角度がわかれば余弦定理から距離がわかる。
    //c^2 = a^2 + b^2 - 2*a*b*cos(theta)
    long double theta = 2.0*PI*((H+M/60.0)/12.0 - M/60.0);
    long double c = sqrtl(A*A + B*B - 2.0*A*B*cosl(theta));
    cout << fixed << setprecision(20) << c << endl;
}

int main(){
    input();
    solve();
    return 0;
}

//4.56425719433005567605