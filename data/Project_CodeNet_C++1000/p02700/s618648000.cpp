#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool judge;
  
  for(int i = 0; i < 105; i++){
    c = c - b;
    if(c <= 0){
      judge = true;
      break;
    }
    a = a - d;
    if(a <= 0){
      judge = false;
      break;
    }
  }
  
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    
