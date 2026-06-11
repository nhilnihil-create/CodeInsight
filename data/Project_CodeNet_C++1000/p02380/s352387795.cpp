#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int a; // 三角形の２辺
    int b; // 三角形の２辺
    int C; // その間の角度

    double s; // 三角形の面積
    double l; // 三角形の周の長さ
    double h; // aを底辺としたときの高さ

    double c;
    double rad; // ラジアン
    double PI = acos(-1); // 円周率
    // cout << PI << endl;

    cin >> a >> b >> C;
    // cout << a << endl;
    // cout << b << endl;
    // cout << C << endl;

    rad = C * PI / 180;
    // cout << rad << endl;
    // cout << ((double)1 / (double)2) * a * b * sin(rad) << endl;
    s = a * b * sin(rad) / 2;

    c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(rad)));
    // printf("%lf\n", c);
    l = a + b + c;

    h = b * sin(rad);

    printf("%lf\n", s);
    printf("%lf\n", l);
    printf("%lf\n", h);

    return 0;
}
