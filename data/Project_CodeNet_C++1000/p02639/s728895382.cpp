//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int a;
  rep1(i, 5){
    cin >> a;
    if(a == 0){
      cout << (i+1);
    }
  }

}