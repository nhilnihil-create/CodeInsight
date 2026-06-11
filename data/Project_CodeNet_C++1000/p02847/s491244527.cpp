#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;
  
  cin >> s;

  vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  
  int flag = 0;
  int i=0;
  
  for(;;){
    if(s == day.at(i)){
      cout << 7-flag;
      break;
    }
    flag++;
    i++;
  }
    
}
