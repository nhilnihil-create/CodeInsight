//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin >> s;
  rep1(i, s.size()){
    cout << 'x';
  }
}