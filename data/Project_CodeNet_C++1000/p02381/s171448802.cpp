// StandardDeviation.cc
// n 人の学生を含むクラスでプログラミングの試験を行った。
// それぞれの得点をs1, s2 ... snとしたときの、標準偏差を求めるプログラムを作成せよ。
//
// 得点の平均値をｍとすれば、分散α2は以下の式で得られる：
// α^2 = (∑i=1 n (s[i] - m)^2) / n
//
// 分散の正の平方根が標準偏差αとなる。
//
// 【入力】
// 複数のデータセットが入力として与えられる。各データセットは以下の形式で与えられる：
// 学生の数 n
// s1 s2 ... sn
// n が 0 のとき入力の終わりとする。
// 【出力】
// 各データセットに対して、標準偏差を１行に出力せよ。
// ただし、0.0001以下の誤差があってもよい。
// 【制約】
// ・入力で与えられる n が1000を超えることはない。
// ・0 ≤ si ≤ 100
// 【例】
// 入力：
// 5
// 70 80 100 90 20
// 3
// 80 80 80
// 0
// 出力：
// 27.85677655
// 0.00000000
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main( void) {
  int n;	// 学生の数；
  int s[1000];	// 得点。学生は1000人を超えることはない。
  double S;	// 得点の合計
  double m;	// 平均点
  double sigma;
  double alpha;	// 標準偏差

  while ( true) {
    cin >> n;
    if ( n == 0) break;

    S = (double)0;
    for ( int i = 0; i < n; i++) {
      cin >> s[i];
      S += s[i];
    }

    m = S / n;

    sigma = 0;
    for ( int i = 0; i < n; i++) {
      sigma += pow( s[i] - m, 2);
    }
    
    alpha = sqrt( sigma / n);

    printf( "%.8lf\n", alpha);
  }

  return 0;
}

