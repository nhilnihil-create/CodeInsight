#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;

void makeStr(int i, char x, string s){
  if(i == n){
    cout << s << endl;
  }else{
    for(char c = 'a'; c <= x+1; c++){
      if(c != x+1){
      	makeStr(i+1, x, s + c);  
      }else{
        makeStr(i+1, c, s + c);
      }
    }
  }
}

int main() {
  cin >> n;
  
  makeStr(1, 'a', "a");
  return 0;
}