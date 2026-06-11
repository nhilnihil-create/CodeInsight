#include <bits/stdc++.h>
using namespace std;
int main() {
  
  //必要な箱を用意
  bool A ; //あるかどうかの判定
  int N; //入力した数字
  
  cin >> N;
  A = false;
  
  for(int i = 1; i < 10 ;i++){
    for(int j = 1; j < 10 ; j++){
      if ( N == i*j)
        A = true;
    }
  }
  if (A == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
}
      
  
