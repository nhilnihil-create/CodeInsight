#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 177, task a, 2020/09/07
//ms,
/*
*/

int main(void){
  int64_t x;
  cin >>x;
  vector<pair<int, int>> factor;
  int64_t ans_a, ans_b;

  for(int i=1;i*i<=x;i++){
    if(x%i==0) factor.push_back({i, x/i});
  }

  for(pair p:factor){
    int64_t A=p.first;
    int64_t B=p.second;
    for(long int i=0;i*i<=4*x;i++){
      int64_t a=i;
      int64_t b=i-A;
      if(a*a*a*a+a*a*a*b+a*a*b*b+a*b*b*b+b*b*b*b==B) {
        ans_a=a;
        ans_b=b;
        goto OUT;
      }
    }
  }

  OUT:cout <<ans_a <<" " <<ans_b <<endl;
  return 0;
}
/*
Aだけは正の数に固定していい。というのも
A<0, B>0 then x<0
A<0, B<0 then A=absB, B=absAでいい。
全探索しようにも範囲がわからない。グラフへの置き換えも多分悪手。

これは整数問題だ。
因数分解したら場合の数を削減できる。
さらにaの上側の制約を見つけたら、探索ができる。bはaとAが決まれば決まる。
aの上側の制約だけど、2Aより大きいとどう考えてもアウト。そこまで試せばいい。
*/
