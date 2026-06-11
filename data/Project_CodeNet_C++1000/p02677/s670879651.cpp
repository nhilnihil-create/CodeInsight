#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//H時M分の時Acm時針,Bcm分針の先端間の距離を出力
//時針の角度：((H*60+M)/(12*60))*(全角度)
//時計を、x軸右方向を0時とする
//時針先端の座標：(A*cos(角度),A*sin(角度))
//分針同様
int main(){
    double A,B,H,M;
    cin >> A >> B >> H >> M;
    double dis;

    double A_range = 2*M_PI*((H*60+M)/(12*60));
    double B_range = 2*M_PI*(M/60);
    dis=pow(A*cos(A_range)-B*cos(B_range),2)+pow(A*sin(A_range)-B*sin(B_range),2);
    dis=sqrt(dis);

    cout << fixed << setprecision(15) << dis << endl;
}