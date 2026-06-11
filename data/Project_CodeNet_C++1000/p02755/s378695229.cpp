//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  int a, b;
  cin >> a >> b;
  int kakaku(int, int);
  cout << kakaku(a,b);
}

int kakaku(int a, int b){
  rep2(i, 1, 10001){
    if(floor(i*0.08) == a && floor(i*0.1) == b){
      return i;
    }
  }
  return -1;
}