
/// @file xor_sum.cc
/// @brief xor_sum の実装ファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2019 Yusuke Matsunaga
/// All rights reserved.


#include <iostream>
#include <vector>


using namespace std;


int
main(int argc,
     char** argv)
{
  int n;
  cin >> n;

  vector<long int> a_list(n);
  int max_bit = 60;
  // ビットごとの出現数が奇数の場合，
  // どのような振り分けを行っても 1 になる．
  // その値を odd とする．
  long int odd = 0;
  for ( int i = 0; i < n; ++ i ) {
    long int a;
    cin >> a;
    a_list[i] = a;
    odd ^= a;
  }

  // odd のビットを落としたデータを a1_list に入れる．
  // 結果，a1_list の要素のすべてのXORをとると0になる．
  vector<long int> a1_list(n);
  for ( int i = 0; i < n; ++ i ) {
    a1_list[i] = a_list[i] & ~odd;
  }

  // a1_list のデータを2つのグループに分割してグループ内
  // で XOR を取ったものの和を最大にする．
  // => a1_list の冪集合のうち XOR で最大になる集合を求める．
  // => XOR(a1_list) = 0 より片側が最大なら他方も最大となる．
  // a XOR a = 0 となるので a1_list の各データに対して a1_list
  // の他のデータを任意回 XOR しても結果としては1回XORしたか
  // 不変かのどちらかとなる．
  // そこで，a1_list の各データが単位ベクトルになるような変形
  // を施す．結果の単位ベクトルをすべてXORしたものが上記の解
  // となる．
  // 結局，a1_list をブールベクトルの集合と見なした時の線形独立
  // な単位ベクトルを求めることになる．
  int rank = 0;
  for ( int bit = max_bit - 1; bit >= 0; -- bit ) {
    long int bitmask = (1UL << bit);
    // rank 以降で bit が立っているデータを探す．
    for ( int i = rank; i < n; ++ i ) {
      if ( a1_list[i] & bitmask ) {
	// i と rank を入れ替える．
	if ( i > rank ) {
	  auto tmp = a1_list[i];
	  a1_list[i] = a1_list[rank];
	  a1_list[rank] = tmp;
	}
	// rank 以外のデータの bit の位置の1を落とす．
	for ( int j = 0; j < n; ++ j ) {
	  if ( j != rank ) {
	    if ( a1_list[j] & bitmask ) {
	      a1_list[j] ^= a1_list[rank];
	    }
	  }
	}
	++ rank;
	break;
      }
    }
  }

  long int even = 0;
  for ( int i = 0; i < n; ++ i ) {
    even ^= a1_list[i];
  }

  long int val = even * 2 + odd;
  cout << val << endl;

  return 0;
}
