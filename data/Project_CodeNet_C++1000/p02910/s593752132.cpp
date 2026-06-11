#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  string s;
  cin >> s;
  int n=s.size();
  bool good=true;
  rep(i,n){
    if(i%2 == 0){
      if(s[i] == 'L'){
        good = false;
      }
    }else{
      if(s[i] == 'R'){
        good = false;
      }
    }
  }

  if(good){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return(0);
}
