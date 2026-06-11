#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double PI = acos(-1);
    double rad,a,b,C,S,L,h;

    cout << fixed << setprecision(12);
    cin >> a >> b >> C;
    rad = C * PI / 180;
    S = a * b *  sin(rad) / 2;
    cout << S << endl;
    C = sqrt(pow(a,2) + pow(b,2) - (2 * a * b * cos(rad)));
    L = a + b + C;
    cout << L << endl;
    h = b * sin(rad);
    cout << h << endl;
    return 0;
}

