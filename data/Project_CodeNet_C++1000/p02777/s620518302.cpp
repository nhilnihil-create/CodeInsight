//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  string s,t,u;
  cin >> s >> t;
  int a,b;
  cin >> a >> b;
  cin >> u;

  if(s==u){
    a -= 1;
  }
  else{
    b -= 1;
  }
  cout << a << " " << b;
 
 
}