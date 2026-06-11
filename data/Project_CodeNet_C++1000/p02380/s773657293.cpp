// Triangle.cc
// 三角形の２辺 a, b とその間の角 C から、
// その三角形の面積 S、周の長さ L, a を底辺としたときの
// 高さ h を求めるプログラムを作成して下さい。
// 【入力】
// a の長さ, b の長さ, Cの大きさ（度）（整数）が空白区切りで与えられます。
// 【出力】
// S, L, h をそれぞれ1行に出力して下さい。0.0001以下の誤差があってもよいものとします。
// 【例】
// 入力：
// 4 3 90
// 出力：
// 6.00000000
// 12.00000000
// 3.00000000
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main( void) {
  double a, b;
  double C;
  double PI = acos(-1);
  double rad;
  double S, L, h;

  cin >> a >> b >> C;

  rad = ( C * PI) / 180;
  h = b * sin( rad);

  S = ( a * b * sin( rad)) /2;

  L = a + b + sqrt( pow( a, 2) + pow( b, 2) - 2 * a * b * cos(rad));

  printf( "%.8lf\n", S);
  printf( "%.8lf\n", L);
  printf( "%.8lf\n", h);

  return 0;
}

