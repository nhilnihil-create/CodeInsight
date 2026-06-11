// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    double a, b, k;

    cin >> a >> b >> k;

    double vol = a * a * b;
    double pi = acos(-1);


    double d = atan(b / a);

    if (vol / 2 < k) {
        int amari = vol - k;
        double ans = atan(amari*2.0 / (a * a * a));
        printf("%.10f", ans*180/pi);

    }
    else if (vol / 2 == k) {
        printf("%.10f", d*180/pi);
    }
    else {
        double ans = pi/2- atan(2.0 * k / (a * b * b));
        printf("%.10f", ans*180/pi);

    }
    return 0;
}

