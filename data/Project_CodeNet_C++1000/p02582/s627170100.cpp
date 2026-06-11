//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  string s;
  cin >> s;
  int n = 3;
  int tem = 0;
  vector<int> lan(0);
  for(int l = 0; l < n;){
    int r = 0;
    for(; l + r < n && s[l] == s[l+r]; r++){}
    if(s[l] == 'R'){
      lan.push_back(r);
    }
      l += r;
      r = 0;
  }
  lan.push_back(0);
  cout << *max_element(lan.begin(), lan.end());
}