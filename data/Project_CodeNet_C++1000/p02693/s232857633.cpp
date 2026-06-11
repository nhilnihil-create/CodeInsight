#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int k;
  int a, b;
  cin >> k >> a >> b;
  
  int c = 0;
  for(int i = a; i <= b; i++){
    if(i % k == 0){
      c = 1;
      break;
    }
  }
  
  if(c != 0){
    cout << "OK"  << endl;
  }
  else{
    cout << "NG" << endl;
  }

}

