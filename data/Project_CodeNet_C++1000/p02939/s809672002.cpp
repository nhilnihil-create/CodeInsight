#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int cnt = 0;
  bool chkOne = false;
  int index = 0;
  
  cin >> str;
  int num = str.size();

  while(index < num){
    if(index == num - 2 && str.at(index) == str.at(index + 1)){
      cnt++;
      break;
    }
    
    if(chkOne && str.at(index) == str.at(index - 1)){
      cnt++;
      index += 2;
      chkOne = false;
    }else{
      cnt++;
      index++;
      chkOne = true;
    }
  }
  
  cout << cnt;
}
