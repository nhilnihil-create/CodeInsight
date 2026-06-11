//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int h ,n;
  cin >> h >> n;
  int sum = 0;
  int tem;
  rep1(i, n){
    cin >> tem;
    sum += tem;
  }
  if(sum < h)cout << "No";
  else cout << "Yes";
}