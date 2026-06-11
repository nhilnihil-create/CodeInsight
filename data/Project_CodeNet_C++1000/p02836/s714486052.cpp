#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  string s2;
  
  cin >> s;
  
  s2 = s;

  int n = s.size();

  int flag = 0;
  
  //reverse(s.begin(),s.end());
  
  rep(i,s.size()/2){
    if(s.at(i)!=s.at(n-i-1))
    flag++;
  }

  cout << flag;
  
  //cout << flag;

}
