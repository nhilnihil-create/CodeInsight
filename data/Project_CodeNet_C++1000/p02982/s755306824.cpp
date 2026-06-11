#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;//データの数
  int D;//次元の数
  int count;//何通りあるかを計算
  
  //データ入力部
  cin >> N >> D;
  
  //それぞれの位置を入れる配列を用意
  vector<vector <int>> X(N,vector <int> (D));
  
  //データ入力部2
  for (int i=0; i<N;i++){
    for(int j=0; j<D; j++){
      cin >> X.at(i).at(j);
    }
  }
  
  //距離の計算と判定
  for (int i=0; i<N-1;i++){
    for (int j=i+1;j<N;j++){
      int Dis =0;
      //距離の計算
      for (int k=0;k<D;k++){
      	Dis += pow((X.at(i).at(k) -X.at(j).at(k)),2);
      }
      //整数になるかどうかの判定
      for (int k=0;pow(k,2) <= Dis;k++){
        if (Dis == pow(k,2))
          count++;
      }
    }
  }
  
  //結果を出力
  cout << count <<endl;

}
    
  
  