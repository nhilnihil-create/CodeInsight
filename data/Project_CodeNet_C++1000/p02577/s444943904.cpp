#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  string N;
  cin >> N;
  
  int size = N.length();
  
  int count = 0;

  for (int i = 0; i < size; ++i) {
    count += (int)(N[i] - '0');  //str[i]　はchar型なのでchar→intへ変換
  }
 
  if(count % 9 ==0){
   cout << "Yes" << endl;
  }else{
   cout << "No" << endl; 
  }
 
}