#include<iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if(a >= 1&&a <= 9){
    if(b >= 1 && b <= 9){
      cout << a * b;
    }
    else{
      cout << -1;
    }
  }
  else{
    cout << -1;
  }
}