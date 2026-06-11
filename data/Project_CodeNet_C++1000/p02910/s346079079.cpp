#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  rep(i, s.size()){
    if (i % 2 == 1){
      if (s[i] == 'R'){
        cout << "No" << endl;
        return 0;
      }
    }

    if (i % 2 == 0){
      if (s[i] == 'L'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
