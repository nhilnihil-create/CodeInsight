#include <iostream>

using namespace std;

int main(){
  double N;
  cin >> N;
  // 入力終わり

  // Xのdoubleを計算
  double tmp = N*100/108;
  // doubleの値を切り上げ
  int X = tmp;
  if(tmp != X)
    X++;
  // Nに一致するかの確認
  double money = X*1.08;

  if((int)money == N)
    cout << X << endl;
  else
    cout << ":(" << endl;
      
  return 0;
}
