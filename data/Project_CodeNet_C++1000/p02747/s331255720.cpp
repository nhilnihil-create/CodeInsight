#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int flag = 0;
  int n = s.size();
  if(n%2 != 0){
    flag = 1;
  }
  else{
  for(int i=0;i<n;i++){
    if(i%2 == 0){
      if(s.at(i)!='h'){
        flag = 1;
        break;
      }
    }
     else{
      if(s.at(i)!='i'){
        flag = 1;
        break;
      }
    }
  }
  }
  if(flag == 0){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
}
}