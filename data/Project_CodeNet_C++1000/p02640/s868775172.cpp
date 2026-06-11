//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int X,Y;
  string judge(int, int);
  cin >> X >> Y;
  cout << judge(X, Y);
}

string judge(int x, int y){
  rep1(i, x+1){
    if(2*i + 4*(x-i) == y){
      return "Yes";
    }
  }
  return "No";
}