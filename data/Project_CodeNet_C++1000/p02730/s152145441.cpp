//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  string s;
  cin >> s;
  int n = s.size();
  bool kaibun(string);
  string t,u;
  rep1(i, (n-1)/2){
    t.push_back(s[i]);
  }
  rep1(i, (n-1)/2){
    u.push_back(s[(n+3)/2 - 1 + i]);
  }
  if(kaibun(s) && kaibun(t) && kaibun(u)){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}

bool kaibun(string s){
  rep1(i, (s.size())/2){
    if(s[i] != s[s.size()-1-i]){
      return false;
    }
  }
  return true;
}