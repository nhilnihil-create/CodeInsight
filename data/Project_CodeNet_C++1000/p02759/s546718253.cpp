#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力を受け取る
  int N;
  cin >> N;

  // 計算
  
  // 両面印刷できないページはあるka 
  bool po = (N % 2) == 1;
  int  pageNum = (N / 2);
  
  if (po) {
    pageNum++;
  }
  
  // 出力
  cout << pageNum << endl;
}