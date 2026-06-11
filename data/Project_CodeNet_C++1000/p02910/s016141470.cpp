#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;

  cin >> s;

  int flag = 1;

  rep(i,s.size()){
    if(i%2 == 0){
      if(s.at(i) == 'R' || s.at(i) == 'U' || s.at(i) == 'D'){

      }

      else
      {
        flag = 0;
      }
      
    }

    else{
      if(s.at(i) == 'L' || s.at(i) == 'U' || s.at(i) == 'D'){}
      else
      {
        flag = 0;
      }
      
    }
  }

  if(flag)
  cout << "Yes";
  else
  {
    cout << "No";
  }
  
}
