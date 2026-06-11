// Distance2.cc
// ２つのデータがどれだけ似ているかを、それらの距離で測る手法は、
// クラスタリングや分類など、様々なところで使われています。
// ここでは、２つの n 次元ベクトル x={x1,x2,...,xn} と y={y1,y2,...,yn}
// の距離を計算してみましょう。
//
// このようなデータの距離を測る指標のひとつとして、次のミンコフスキー距離が知られています。 
//   Dxy=(∑i=1 to n |xi−yi|^p ) ^ (1/p)
//
// p=1 のとき 
//   Dxy= |x1−y1| + |x2−y2| + ... + |xn−yn|
//
// となり、これはマンハッタン距離とよばれます。 
//
// p=2 のとき 
//   Dxy=sqrt ( (|x1−y1|)^2 + (|x2−y2|)^2 + ... + (|xn−yn|)^2) 
//
// となり、これは一般的に使われるユークリッド距離になります。 
//
// p=∞ のとき 
//   Dxy=max i=1 to n (|xi−yi|)
//
// となり、これはチェビシェフ距離と呼ばれます。
//
// ２つの n 次元ベクトルが与えられるので、p がそれぞれ 1、2、3、∞ の
// ミンコフスキー距離を求めるプログラムを作成してください。
//
// 【入力】
// １行目に整数 n が与えられます。２行目にベクトル x の要素 {x1,x2,...xn}、
// ３行目にベクトル y の要素 {y1,y2,...yn} が空白区切りで与えられます。
// 入力はすべて整数値です。
// 【出力】
// p がそれぞれ 1、2、3、∞ の順番にそれぞれ１行に距離を出力してください。
// ただし、0.00001 以下の誤差があってもよいものとします。
// 【制約】
// ・1≤n≤100
// ・0≤xi,yi≤1000
// 【例】
// 入力：
// 3
// 1 2 3
// 2 0 4
// 出力：
// 4.000000
// 2.449490
// 2.154435
// 2.000000
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main( void) {
  int n;
  int x[100];
  int y[100];
  double Dxy, maxDxy;

  cin >> n;

  for ( int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for ( int i = 0; i < n; i++) {
    cin >> y[i];
  }

  // p = 1の時
  Dxy = 0;
  for ( int i = 0; i < n; i++) {
    Dxy += fabs( (double)(x[i] - y[i]));
  }
  printf( "%.6lf\n", Dxy);

  // p = 2の時
  Dxy = 0;
  for ( int i = 0; i < n; i++) {
    Dxy += pow( fabs( x[i] - y[i]), 2);
  }
  Dxy = sqrt( Dxy);
  printf( "%.6lf\n", Dxy);

  // p = 3の時
  Dxy = 0;
  for ( int i = 0; i < n; i++) {
    Dxy += pow( fabs( x[i] - y[i]), 3);
  }
  Dxy = pow( Dxy, (double)1/3);
  printf( "%.6lf\n", Dxy);
  
  // p = ∞の時
  maxDxy = 0;
  for ( int i = 0; i < n; i++) {
    Dxy = fabs( (double)(x[i] - y[i]));
    if ( Dxy > maxDxy) maxDxy = Dxy;
  }
  printf( "%.6lf\n", maxDxy);

  return 0;
}

