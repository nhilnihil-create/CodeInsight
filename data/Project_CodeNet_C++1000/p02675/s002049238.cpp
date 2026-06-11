#include <bits/stdc++.h> 
using namespace std; 
int main(){
  int i;
  cin >> i;
  int k = i % 10;
  
  if (k== 2 || k == 4 || k == 5 || k == 7 || k ==  9){
    cout << "hon" << endl;
  }
  
  else if (k == 0 || k == 1 || k == 6 || k == 8 ){
    cout << "pon" << endl;
  }
  else {
    cout << "bon" << endl;
  }
}