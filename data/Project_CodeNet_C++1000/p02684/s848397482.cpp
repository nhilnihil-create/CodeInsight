#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 167, task d, 2020/09/03
//ms,
/*
*/

int main(void){
  int N;
  int64_t K;
  vector<int> a;
  map<int, int> report;//key:訪れた町, value:遷移回数
  int loc=0;
  int mv_ctr=0;
  int cycle;
  int ans_ctr;
  int ans;

  cin >>N >>K;
  for(int i=0;i<N;i++){
    int tmp;
    cin >>tmp;
    tmp--;
    a.push_back(tmp);
  }

  while(report.count(loc)==0 && mv_ctr<=K){
    report[loc]=mv_ctr;
    mv_ctr++;
    loc=a[loc];
  }

  cycle=mv_ctr-report[loc];
  ans_ctr=(K-report[loc])%cycle+report[loc];//ここに問題ありでは？？

  for(pair<int, int> p:report){
    int loc=p.first;
    int ctr=p.second;
    if(ctr==ans_ctr) {
      ans=loc;
      break;
    }
  }

  ans++;
  cout <<ans <<endl;;
  return 0;
}
/*
Kが大きい。
ループして戻ってくるまでやり続けるのは余裕で間に合う。
mapかなあ。
順番を保存していて検索がNオーダー未満のデータ構造とかあったっけ。
mapを使ってうまいことやる、かなあ。
一応方針は合ってる。

ループしないときを忘れてる！
*/
