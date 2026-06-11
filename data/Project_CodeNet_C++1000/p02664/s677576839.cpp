#include <bits/stdc++.h>
using namespace std;
#define  itn int
using ll=int64_t;
#define rep(i,n) for (int i = 0; i < (int) (n); i++)
using vi = vector<int>;
using vll = vector<ll>;
/*//再帰関数木構造定型
int complete_time(vector<vector<int>> &children, int x) {
  // ベースケース
  if (children.at(x).size() == 0) {
    return 1;  // 子組織が無いような組織について、報告書が揃う時刻は0
  }// 再帰ステップ
  int receive_maisuu = 1;  // 受け取った時刻の最大値
  // x番の組織の子組織についてループ
  for (int c : children.at(x)) {receive_maisuu  += complete_time(children, c) ;}
  return  receive_maisuu ;
}*/


// 組織の関係から2次元配列を作る
//二次元配列入力定型
/*
vector<vector<int>> children(N);  // ある組織の子組織の番号一覧
  for (int i = 1; i < N; i++) {
    int parent = p.at(i);  // i番の親組織の番号
    children.at(parent).push_back(i);  // parentの子組織一覧にi番を追加
  }

  // num個分のスペースからなる文字列を返す (字下げに用いる)
  string space(int num) {
    string ret = "";
    for (int i = 0; i < num; i++) {
      ret += " ";
    }
    return ret;
  }*/


int main(){
string t;
cin>>t;
rep(i,t.size()){
  if(t.at(i)=='?')t.at(i)='D';
}
  cout<<t;
  
  

  
  

}
