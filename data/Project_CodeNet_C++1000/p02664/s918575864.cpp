#include <bits/stdc++.h>
using namespace std;

int main(){
  string T;
  cin >> T;

  string ans= T;
  for(auto &c:ans){
    if(c=='?'){
      c= 'D';
    }
  }
  
  cout << ans << endl;
}