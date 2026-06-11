#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int l = s.size();
  vector<int> dp(l);
  dp.at(0) = 1;
  if(l >= 2){
    if(s.at(0) == s.at(1)) dp.at(1) = 1;
    else dp.at(1) = 2;
    if(l >= 3){
      if(s.at(1) == s.at(2)) dp.at(2) = 2;
      else dp.at(2) = dp.at(1) + 1;
    }
  }
  if(l >= 4){
    for(int i = 3; i < l; i++){
      if(s.at(i) == s.at(i-1)) dp.at(i) = dp.at(i-3) + 2;
      else dp.at(i) = dp.at(i-1) + 1;
    }
  }
  
  cout << dp.at(l-1) << endl;
}