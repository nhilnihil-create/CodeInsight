//ITP1_10_A_19140837_Ojima_Yukiya.cpp
//提出日 2020/6/24 wednesday
//プログラミング基礎演習2 CS 第７回課題 ITP1_10_A
//学修番号 19140837　小島優希也
#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%lf", sqrt((a - c)*(a - c) + (b - d)*(b - d)));
    return 0;
}
