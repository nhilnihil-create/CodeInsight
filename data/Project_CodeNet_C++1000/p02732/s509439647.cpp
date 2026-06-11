#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 159, task d, 2020/09/08
//ms,
/*
方針は完璧だった。
recをintにしたのがバグの原因。
recそのものがintでおさまらないことはない。
だけどcasesに加えるとき、右辺の計算が一度intで処理されてしまうんだと思う。
recをint64_tにしたら通るし、右辺の計算時に一部にint64_tを含めばそれだけで勝ち。
*/

int main(void){
  int N;
  vector<int> rec(200001);//インデックスはボールに書かれた数字、要素は個数
  vector<int> a;
  int64_t cases=0;

  for(int i=0;i<200000;i++) rec[i]=0;

  cin >>N;
  for(int i=0;i<N;i++){
    int tmp_a;
    cin >>tmp_a;
    rec[tmp_a]++;
    a.push_back(tmp_a);
  }

  int64_t one=1;
  for(int i=1;i<200000;i++) cases+=one*rec[i]*(rec[i]-1)/2;

  for(int i=0;i<N;i++){
    int same_balls =rec[a[i]];
    int64_t ans=cases - same_balls*(same_balls-1)/2;
    ans += (same_balls-1)*(same_balls-2)/2;
    cout <<ans <<endl;

  }


  return 0;
}
/*
*/
