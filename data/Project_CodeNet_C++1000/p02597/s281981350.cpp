//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int n;
  cin >> n;
  string c;
  cin >> c;
  int ans = 0;
  int n_red = count(c.begin(), c.end(), 'R');
  char white = 'W';
  rep1(i, n_red){
    char moji = c[i];
    
    if(moji == white){
      ans++;
    }
  }
    
  cout << ans;

}