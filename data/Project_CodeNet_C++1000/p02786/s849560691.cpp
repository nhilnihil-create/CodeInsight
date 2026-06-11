//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  long long h;
  cin >> h;
  long long ans = 0;
  int i = 0;
  while(powl(2, i) <= h){
    ans += pow(2, i);
    i += 1;
  }
  cout << ans;
}