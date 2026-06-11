#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  bool ans = 1;
  for(int i=0;i<s.size();i++){
    if(i%2 == 0 && s.at(i) == 'L'){
      ans = 0;
    }
    else if(i%2 == 1 && s.at(i) == 'R'){
      ans = 0;
    }
  }
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}