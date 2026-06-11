#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;//データの数
  
  int count = 0;//何種類あるかを数える関数
  
  
    
  //　入力部
  cin >> N;
  vector <int> data(N) ;//　余裕をもって150個のデータを用意
  
  for(int i = 0; i < N ;i++){
  	cin >> data.at(i);  
  }
  
  //　データの並び替え
  sort(data.begin(),data.end());
    
  // 三つの組み合わせを決める
  if (N >=3){
  for(int i= 0; i<N-2;i++){
    for(int k=i+1; k<N-1;k++){
      
      for(int j=k+1;j<N;j++){
        
        if (data.at(i) != data.at(k) && data.at(j) != data.at(k) && (data.at(i) + data.at(k)) > data.at(j))
          
            count ++;
            }
            }
            }
  }
        cout << count <<endl;

     
}

