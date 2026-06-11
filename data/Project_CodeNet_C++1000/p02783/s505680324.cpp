#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  int b;
  cin >> a >> b;
  
  int c = a % b;
    
  if(c == 0){
    cout << a / b << endl;
  }else{
    cout << a / b + 1 << endl;
  }
}