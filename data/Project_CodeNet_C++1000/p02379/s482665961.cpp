// Distance.cc
// ２点 P1(x1, y1), P2(x2, y2) の距離を求めるプログラムを作成せよ。
// 【入力】
// x1, y1, x2, y2 （実数）が空白区切りで与えられます。
// 【出力】
// P1とP2の距離を実数で１行に出力して下さい。0.0001以下の誤差があってもよいものとします。
// 【例】
// 入力１：
// 0 0 1 1
// 出力１:
// 1.41421356
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main( void) {
  double x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;

  printf( "%.8lf\n", sqrt( pow( fabs(x1-x2), 2) + pow( fabs(y1-y2),2)));

  return 0;
}

