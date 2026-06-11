//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
  string s,t;
  cin >> s >> t;
  int ans = 0;
  rep1(i, s.size()){
    if(s[i] != t[i]){
      ans += 1;
    }
  }
  cout << ans;
}